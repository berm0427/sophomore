using System;
using System.Net;
using System.Threading.Tasks;


namespace ServerTime
{

    public static class Time
    {
        /// <summary>
        /// 클라이언트와 동기화된 시간 차이 (Tick)
        /// </summary>
        private static long diffTick = 0L;

        /// <summary>
        /// 기준 시간
        /// </summary>
        private static DateTime syncTime = DateTime.Now;

        /// <summary>
        /// 현재 시간
        /// </summary>
        public static DateTime NowTime => DateTime.Now.AddTicks(diffTick);

        /// <summary>
        /// UTC 시간 (KST + 9시간)
        /// </summary>
        public static DateTime UtcNowTime => NowTime.AddHours(9f);

        /// <summary>
        /// 동기화 시간 업데이트
        /// </summary>
        /// <param name="dateStr"></param>
        public static void UpdateDateTime(string dateStr)
        {
            if (DateTime.TryParse(dateStr, out DateTime dateTime))
            {
                syncTime = dateTime;
                diffTick = (syncTime - DateTime.Now).Ticks;
            }
        }

        /// <summary>
        /// 서버 동기화
        /// </summary>
        /// <param name="serverURL"></param>
        public static async Task Synchronization(string serverURL)
        {
            WebRequest request = WebRequest.Create(serverURL);
            WebResponse response = await request.GetResponseAsync();

            if (Array.Exists(response.Headers.AllKeys, headerKey => headerKey.Equals("Date")))
                UpdateDateTime(response.Headers["Date"]);
        }
    }

    class Program
    {
        private static bool isCheckIn = false;

        public static async Task Main(string[] args)
        {
            string url = "https://sch.ac.kr";

            // 서버와 클라이언트 시간 동기화
            await Time.Synchronization(url);

            Console.WriteLine($"'{url}'의 서버 시간을 출력합니다. 'q'를 입력하여 종료하세요.");

            while (!isCheckIn)
            {
                // 이전 출력 내용을 덮어쓰기 위해 커서를 첫 번째 줄로 이동합니다.
                Console.SetCursorPosition(0, Console.CursorTop);

                // 서버 기준으로 만들어진 시간으로 사용할 수 있다.
                Console.Write($"서버 시간: {Time.NowTime}");

                if (Console.KeyAvailable)
                {
                    ConsoleKeyInfo keyInfo = Console.ReadKey(intercept: true);
                    if (keyInfo.KeyChar == 'q' || keyInfo.KeyChar == 'Q')
                    {
                        isCheckIn = true; // 'q' 입력 시 종료
                    }
                }
            }
        }
    }
}
