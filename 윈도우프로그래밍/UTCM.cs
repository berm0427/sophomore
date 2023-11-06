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
        private Timer timer;
        private Dictionary<string, string> countryToTimezoneMap;

        public MainForm()
        {
            // Initialize the dictionary with some country-timezone pairs.
            countryToTimezoneMap = new Dictionary<string, string>
            {
                { "Korea", "Asia/Seoul" },
                // Add more countries and their respective timezone IDs here.
                { "USA", "America/New_York" }, // Example for multiple entries
                { "Japan", "Asia/Tokyo" },
                { "DPRK", "Asia/Pyongyang"}
            };

            timeLabel = new Label() { Location = new System.Drawing.Point(10, 10), Size = new System.Drawing.Size(300, 20) };
            countryTextBox = new TextBox() { Location = new System.Drawing.Point(10, 40), Width = 200 };
            timer = new Timer() { Interval = 1000 };

            this.Controls.Add(timeLabel);
            this.Controls.Add(countryTextBox);
            this.Controls.Add(new Label() { Location = new System.Drawing.Point(10, 70), Size = new System.Drawing.Size(300, 20), Text = "Enter a country name and press Enter" });

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
                e.SuppressKeyPress = true; // To prevent ding sound on pressing Enter
            }
        }

        private void UpdateTime()
        {
            string countryInput = countryTextBox.Text.Trim();
            DateTime currentTime = DateTime.UtcNow;

            if (!string.IsNullOrWhiteSpace(countryInput))
            {
                try
                {
                    if (countryToTimezoneMap.TryGetValue(countryInput, out var timezoneId))
                    {
                        TimeZoneInfo timeZoneInfo = TZConvert.GetTimeZoneInfo(timezoneId);
                        currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, timeZoneInfo);
                    }
                    else
                    {
                        timeLabel.Text = "Invalid country name or timezone not found";
                        return;
                    }
                }
                catch (Exception ex)
                {
                    // Handle any unexpected error here
                    timeLabel.Text = "Error: " + ex.Message;
                    return;
                }
            }

            timeLabel.Text = $"{countryInput} Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
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
