using System;
using System.Windows.Forms;

namespace KSTTimerApp
{
    public class MainForm : Form
    {
        private Label kstLabel;
        private Timer timer;

        public MainForm()
        {
            kstLabel = new Label()
            {
                Location = new System.Drawing.Point(10, 10),
                Width = 200
            };
            this.Controls.Add(kstLabel);

            timer = new Timer();
            timer.Interval = 1000; // 1초마다 업데이트
            timer.Tick += Timer_Tick;
            timer.Start();

            UpdateKST();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            UpdateKST();
        }

        private void UpdateKST()
        {
            // 현재 UTC 시간에 9시간을 더하여 KST로 변환
            DateTime kstTime = DateTime.UtcNow.AddHours(9);
            kstLabel.Text = $"KST: {kstTime.ToString("yyyy-MM-dd HH:mm:ss")}";
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
