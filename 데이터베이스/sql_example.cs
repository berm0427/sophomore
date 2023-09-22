using System;
using MySql.Data.MySqlClient;

namespace ConsoleApp1
{
    class sql_example

    {
        static void Main(string[] args)
        {
            MySqlConnection con = new MySqlConnection();
            con.ConnectionString = "Server=localhost;Port=3306;Database=testdb;Uid=root;Pwd=rootroot;";
            con.Open();
            MySqlCommand com = new MySqlCommand("INSERT INTO testTable(name,height,profile) VALUES('유창4','146','hello')",con);
            
            
            if (com.ExecuteNonQuery() == 1)
            {
                Console.WriteLine("성공");
            }
            else
            {
                Console.WriteLine("실패");
            }
        }
    }
}

// https://www.nuget.org/packages/MySql.Data
// DB Setting