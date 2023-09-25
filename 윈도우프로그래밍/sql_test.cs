using System;
using MySql.Data.MySqlClient;

namespace ConsoleApp1
{
    class sql_test

    {
        static void Main(string[] args)
        {
            MySqlConnection con = new MySqlConnection();
            con.ConnectionString = "Server=localhost;Port=3306;Database=testdb;Uid=root;Pwd=rootroot;";
            con.Open();
            MySqlCommand com = new MySqlCommand("INSERT INTO testTable(id, name,height,profile) VALUES(1, '유창범','176','hello')",con);
            
            
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
// testdb, testTable 만들고 진행
// create testdb;
/* CREATE TABLE testTable(
  id INT(11) NOT NULL AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  ouccupation VARCHAR(20) NULL,
  height SMALLINT,
  profile TEXT NULL,
  date  DATETIME,
  CONSTRAINT testTable_PK PRIMARY KEY(id)
); */