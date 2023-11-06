using System;
using System.Collections.Generic;
using System.Windows.Forms;
using TimeZoneConverter;

namespace TimeZoneApp
{
    public partial class MainForm : Form
    {
        private Label timeLabel;
        private TextBox countryTextBox;
        private TextBox timezoneTextBox;
        private Button addButton;
        private ListBox mappingListBox;
        private Timer timer;
        private Dictionary<string, string> countryToTimezoneMap;

        public MainForm()
        {
            countryToTimezoneMap = new Dictionary<string, string>();
            InitializeComponent();

            timeLabel = new Label() { Location = new System.Drawing.Point(10, 10), Size = new System.Drawing.Size(300, 20) };
            countryTextBox = new TextBox() { Location = new System.Drawing.Point(10, 40), Width = 200 };
            timezoneTextBox = new TextBox() { Location = new System.Drawing.Point(220, 40), Width = 200 };
            addButton = new Button() { Location = new System.Drawing.Point(430, 40), Text = "Add", Width = 100 };
            mappingListBox = new ListBox() { Location = new System.Drawing.Point(10, 70), Size = new System.Drawing.Size(520, 100) };
            timer = new Timer() { Interval = 1000 };

            this.Controls.Add(timeLabel);
            this.Controls.Add(countryTextBox);
            this.Controls.Add(timezoneTextBox);
            this.Controls.Add(addButton);
            this.Controls.Add(mappingListBox);

            countryTextBox.KeyDown += CountryTextBox_KeyDown;
            timezoneTextBox.KeyDown += TimezoneTextBox_KeyDown;
            addButton.Click += AddButton_Click;
            timer.Tick += Timer_Tick;

            timer.Start();
            UpdateTime();
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            string country = countryTextBox.Text.Trim();
            string timezone = timezoneTextBox.Text.Trim();

            if (!string.IsNullOrWhiteSpace(country) && !string.IsNullOrWhiteSpace(timezone))
            {
                if (TZConvert.KnownIanaTimeZoneNames.Contains(timezone))
                {
                    countryToTimezoneMap[country] = timezone;
                    UpdateMappingListBox();
                    countryTextBox.Clear();
                    timezoneTextBox.Clear();
                }
                else
                {
                    MessageBox.Show("Invalid timezone identifier.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void UpdateMappingListBox()
        {
            mappingListBox.Items.Clear();
            foreach (var mapping in countryToTimezoneMap)
            {
                mappingListBox.Items.Add($"{mapping.Key} - {mapping.Value}");
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            UpdateTime();
        }

        private void CountryTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                timezoneTextBox.Focus();
                e.SuppressKeyPress = true; // To prevent ding sound on pressing Enter
            }
        }

        private void TimezoneTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                AddButton_Click(this, EventArgs.Empty);
                e.SuppressKeyPress = true;
            }
        }

        private void UpdateTime()
        {
            string countryInput = countryTextBox.Text.Trim();
            DateTime currentTime = DateTime.UtcNow;

            if (!string.IsNullOrWhiteSpace(countryInput) && countryToTimezoneMap.TryGetValue(countryInput, out var timezoneId))
            {
                try
                {
                    TimeZoneInfo timeZoneInfo = TZConvert.GetTimeZoneInfo(timezoneId);
                    currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, timeZoneInfo);
                    timeLabel.Text = $"{countryInput} Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
                }
                catch (Exception ex)
                {
                    timeLabel.Text = "Error: " + ex.Message;
                }
            }
        }
    }

    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
