using System;
using System.Collections.Generic;
using System.Windows.Forms;
using TimeZoneConverter; // NuGet 패키지 관리자에서 설치 필요

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
            // 시간대와 국가의 쌍 입력
            countryToTimezoneMap = new Dictionary<string, string>
            {
                // 국가 이름을 아래와 같이 추가
                { "Korea", "Asia/Seoul" },
                { "USA", "America/New_York" },
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
                e.SuppressKeyPress = true; // Enter 키를 누를 때 소리를 방지용
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
