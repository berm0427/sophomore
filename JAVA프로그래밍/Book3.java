import java.util.Scanner;

class Book
{
    String title, author;

    public Book(String title, String author) 
    {
        this.title = title;
        this.author = author;
    }
}

public class Book3 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("책 몇 개나 받을래?: ");
        int num = scanner.nextInt();
        scanner.nextLine(); // 새 줄로 넘기기 위한 용도

        Book[] books = new Book[num];

        for (int i = 0; i < books.length; i++) 
        {
            System.out.print("제목>>");
            String title = scanner.nextLine();
            System.out.print("저자>>");
            String author = scanner.nextLine();
            books[i] = new Book(title, author);
        }

        for (int i = 0; i < books.length; i++) 
        {
            System.out.print("(" + books[i].title + "," + books[i].author + ") ");
        }
        scanner.close();
    }
}