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
        private TextBox timeZoneTextBox; // Added TextBox for custom time zone input
        private Timer timer;
        private Dictionary<string, string> countryToTimezoneMap;

        public MainForm()
        {
            countryToTimezoneMap = new Dictionary<string, string>
            {
                { "Korea", "Asia/Seoul" },
                { "USA", "America/New_York" },
                { "Japan", "Asia/Tokyo" },
                // You can add more country-time zone mappings here
            };

            timeLabel = new Label() { Location = new System.Drawing.Point(10, 10), Size = new System.Drawing.Size(400, 20) };
            countryTextBox = new TextBox() { Location = new System.Drawing.Point(10, 40), Width = 200 };
            timeZoneTextBox = new TextBox() { Location = new System.Drawing.Point(220, 40), Width = 200 }; // Added TextBox for custom time zone
            timer = new Timer() { Interval = 1000 };

            this.Controls.Add(timeLabel);
            this.Controls.Add(countryTextBox);
            this.Controls.Add(timeZoneTextBox); // Added TextBox for custom time zone
            this.Controls.Add(new Label() { Location = new System.Drawing.Point(10, 70), Size = new System.Drawing.Size(400, 20), Text = "Enter a country name or custom time zone and press Enter" });

            countryTextBox.KeyDown += CountryTextBox_KeyDown;
            timeZoneTextBox.KeyDown += CountryTextBox_KeyDown; // Handle Enter key press for custom time zone
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
                e.SuppressKeyPress = true; // Prevent Enter key sound
            }
        }

        private void UpdateTime()
        {
            string input = countryTextBox.Text.Trim();
            DateTime currentTime = DateTime.UtcNow;

            if (!string.IsNullOrWhiteSpace(input))
            {
                try
                {
                    if (countryToTimezoneMap.TryGetValue(input, out var countryTimeZone))
                    {
                        TimeZoneInfo timeZoneInfo = TZConvert.GetTimeZoneInfo(countryTimeZone);
                        currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, timeZoneInfo);
                        timeLabel.Text = $"{input} Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
                    }
                    else
                    {
                        // If the input is not found in the predefined mappings, try it as a custom time zone
                        if (!string.IsNullOrWhiteSpace(timeZoneTextBox.Text))
                        {
                            TimeZoneInfo timeZoneInfo = TZConvert.GetTimeZoneInfo(timeZoneTextBox.Text);
                            currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, timeZoneInfo);
                            timeLabel.Text = $"Custom Time Zone: {currentTime:yyyy-MM-dd HH:mm:ss}";
                        }
                        else
                        {
                            timeLabel.Text = "Invalid country name or time zone not found";
                        }
                    }
                }
                catch (Exception ex)
                {
                    timeLabel.Text = "Error: " + ex.Message;
                }
            }
            else
            {
                timeLabel.Text = $"UTC Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
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
