using System;
using System.Windows.Forms;
using TimeZoneConverter;

namespace TimeZoneApp
{
    public partial class MainForm : Form
    {
        private Label timeLabel;
        private TextBox countryTextBox;
        private Timer timer;

        public MainForm()
        {

            timeLabel = new Label() { Location = new System.Drawing.Point(10, 10), Width = 300 };
            countryTextBox = new TextBox() { Location = new System.Drawing.Point(10, 40), Width = 200 };
            timer = new Timer() { Interval = 1000 };

            this.Controls.Add(timeLabel);
            this.Controls.Add(countryTextBox);
            this.Controls.Add(new Label() { Location = new System.Drawing.Point(10, 70), Text = "Enter a country and press Enter" });

            countryTextBox.KeyDown += CountryTextBox_KeyDown;
            timer.Tick += Timer_Tick;

            timer.Start();
            UpdateTime();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            UpdateTime();
        }

        private void CountryTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                UpdateTime();
                e.SuppressKeyPress = true;
            }
        }

        private void UpdateTime()
        {
            string country = countryTextBox.Text;
            DateTime currentTime = DateTime.UtcNow;

            if (!string.IsNullOrWhiteSpace(country))
            {
                try
                {
                    string timeZoneId = TZConvert.GetTimeZoneInfo(country).Id;
                    currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, TimeZoneInfo.FindSystemTimeZoneById(timeZoneId));
                }
                catch
                {
                    timeLabel.Text = "Invalid country name or timezone not found";
                    return;
                }
            }

            timeLabel.Text = $"{country} Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
        }
    }

    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}

