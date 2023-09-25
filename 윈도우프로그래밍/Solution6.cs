class Solution
{
    class Car
    {
        private void PrivateM() {}
        public void PublicM() {}
        protected void ProtectedM() {}

        public void TestA()
        {
            PrivateM();
            PublicM();
            PrivateM();
        }

        class Sedan : Car
        {
            public void TestB()
            {
                PrivateM(); // 사용 불가
                PublicM();
                ProtectedM();
            }
        }
        static void Main(string[] args)
        {
            Sedan sd = new Sedan();
            sd.PublicM();
            sd.PrivateM(); // 사용 불가
            sd.ProtectedM(); // 사용 블가
        }
    }
    
}