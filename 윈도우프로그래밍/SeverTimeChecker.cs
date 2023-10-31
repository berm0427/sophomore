using System;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ServerTime
{
    public static class Time
    {
        private static long diffTick = 0L; // 서버와 클라이언트의 시간 차이 저장
        private static DateTime syncTime = DateTime.Now; // 동기화된 서버의 시간

        public static DateTime NowTime => DateTime.Now.AddTicks(diffTick); // 동기화된 현재 시간
        public static DateTime UtcNowTime => NowTime.AddHours(9f); // 동기화된 UTC 시간 (KST 기준 +9시간)

        public static void UpdateDateTime(string dateStr)
        {
            if (DateTime.TryParse(dateStr, out DateTime dateTime))
            {
                syncTime = dateTime;
                diffTick = (syncTime - DateTime.Now).Ticks; // 시간 차이 계산
            }
        }

        public static async Task Synchronization(string serverURL)
        {
            WebRequest request = WebRequest.Create(serverURL);
            WebResponse response = await request.GetResponseAsync();

            if (Array.Exists(response.Headers.AllKeys, headerKey => headerKey.Equals("Date")))
                UpdateDateTime(response.Headers["Date"]); // 헤더에서 날짜 정보 업데이트
        }
    }

    public class MainForm : Form
    {
        private TextBox serverTimeBox; // 서버 시간을 표시하는 텍스트 박스
        private Label serverTimeLabel; // 'Server Time' 레이블
        private TextBox serverUrlBox; // 서버 URL을 입력하는 텍스트 박스
        private Label serverUrlLabel; // 'Server URL' 레이블
        private Button syncButton; // 동기화 버튼

        public MainForm()
        {
            serverUrlLabel = new Label
            {
                Text = "Server URL:",
                Location = new System.Drawing.Point(10, 10),
                Size = new System.Drawing.Size(80, 20)
            };
            Controls.Add(serverUrlLabel);

            serverUrlBox = new TextBox
            {
                Location = new System.Drawing.Point(90, 10),
                Size = new System.Drawing.Size(300, 20)
            };
            Controls.Add(serverUrlBox);

            syncButton = new Button
            {
                Text = "Synchronize",
                Location = new System.Drawing.Point(400, 10),
                Size = new System.Drawing.Size(100, 30)
            };
            syncButton.Click += async (sender, e) => await SynchronizeTime();
            Controls.Add(syncButton);

            serverTimeLabel = new Label
            {
                Text = "Server Time:",
                Location = new System.Drawing.Point(10, 50),
                Size = new System.Drawing.Size(80, 20)
            };
            Controls.Add(serverTimeLabel);

            serverTimeBox = new TextBox
            {
                Location = new System.Drawing.Point(90, 50),
                Size = new System.Drawing.Size(200, 20),
                ReadOnly = true
            };
            Controls.Add(serverTimeBox);

            Text = "Server Time Sync";
            Size = new System.Drawing.Size(520, 110);
        }

        private async Task SynchronizeTime()
        {
            string url = serverUrlBox.Text.Trim();

            if(string.IsNullOrEmpty(url))
            {
                MessageBox.Show("Please enter a server URL.", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            await Time.Synchronization(url);
            serverTimeBox.Text = Time.NowTime.ToString();
        }
    }

    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm()); // 메인 폼 실행
        }
    }
}
