using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;
using TimeZoneConverter;

namespace TimeZoneApp
{
    public partial class MainForm : Form
    {
        private Label timeLabel;
        private TextBox countryTextBox;
        private TextBox timeZoneTextBox;
        private Timer timer;
        private Label countryLabel;
        private Label timeZoneLabel;
        private Dictionary<string, string> countryToTimezoneMap;
        private string storagePath = "CountryTimezoneMappings.txt";

        public MainForm()
        {
            countryToTimezoneMap = LoadMappingsFromFile();

            timeLabel = new Label() { Location = new System.Drawing.Point(10, 10), Size = new System.Drawing.Size(400, 20) };
            countryTextBox = new TextBox() { Location = new System.Drawing.Point(10, 40), Width = 200 };
            timeZoneTextBox = new TextBox() { Location = new System.Drawing.Point(220, 40), Width = 200 };
            timer = new Timer() { Interval = 1000 };

            countryLabel = new Label() { Location = new System.Drawing.Point(10, 70), Size = new System.Drawing.Size(200, 20), Text = "Enter country name" };
            timeZoneLabel = new Label() { Location = new System.Drawing.Point(220, 70), Size = new System.Drawing.Size(200, 20), Text = "Or enter IANA time zone" };

            this.Controls.Add(timeLabel);
            this.Controls.Add(countryTextBox);
            this.Controls.Add(timeZoneTextBox);
            this.Controls.Add(countryLabel);
            this.Controls.Add(timeZoneLabel);

            countryTextBox.KeyDown += CountryTextBox_KeyDown;
            timeZoneTextBox.KeyDown += TimeZoneTextBox_KeyDown;
            timer.Tick += Timer_Tick;

            this.FormClosing += MainForm_FormClosing;

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
                if (!string.IsNullOrWhiteSpace(countryTextBox.Text) && !string.IsNullOrWhiteSpace(timeZoneTextBox.Text))
                {
                    countryToTimezoneMap[countryTextBox.Text.Trim()] = timeZoneTextBox.Text.Trim();
                    SaveMappingsToFile();
                }
                UpdateTime();
                e.SuppressKeyPress = true;
            }
        }

        private void TimeZoneTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                UpdateTime();
                e.SuppressKeyPress = true;
            }
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            SaveMappingsToFile();
        }

        private void UpdateTime()
        {
            string input = countryTextBox.Text.Trim();
            string customTimezone = timeZoneTextBox.Text.Trim();
            DateTime currentTime = DateTime.UtcNow;

            if (!string.IsNullOrWhiteSpace(input) || !string.IsNullOrWhiteSpace(customTimezone))
            {
                try
                {
                    string timezoneId = !string.IsNullOrWhiteSpace(input) ? countryToTimezoneMap[input] : customTimezone;
                    TimeZoneInfo timeZoneInfo = TZConvert.GetTimeZoneInfo(timezoneId);
                    currentTime = TimeZoneInfo.ConvertTimeFromUtc(currentTime, timeZoneInfo);
                    timeLabel.Text = $"{(string.IsNullOrWhiteSpace(input) ? "Custom" : input)} Time: {currentTime:yyyy-MM-dd HH:mm:ss}";
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

        private Dictionary<string, string> LoadMappingsFromFile()
        {
            var mappings = new Dictionary<string, string>();
            if (File.Exists(storagePath))
            {
                foreach (var line in File.ReadAllLines(storagePath))
                {
                    var parts = line.Split('=');
                    if (parts.Length == 2)
                    {
                        mappings[parts[0].Trim()] = parts[1].Trim();
                    }
                }
            }
            return mappings;
        }

        private void SaveMappingsToFile()
        {
            using (var writer = new StreamWriter(storagePath, false))
            {
                foreach (var kvp in countryToTimezoneMap)
                {
                    writer.WriteLine($"{kvp.Key}={kvp.Value}");
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
