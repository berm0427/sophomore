class Parnets
{
    public void familyName()
    {
        System.out.print("김");
    }
    public void name()
    {
        familyName();
        System.out.println("철수");
    }
}

class Son extends Parnets
{
    public void name()
    {
        familyName();
        System.out.println("인직");
    }
}

class Daughter extends Parnets
{
    public void name()
    {
        familyName();
        System.out.println("희선");
    }
}


public class UpcastingEx_1 
{
    public static void main(String[] args) 
    {
        Son s = new Son();
        Daughter d = new Daughter();

        Parnets p1 = s;  // new Parnets();   
        Parnets p2 = d;  // new Parnets();   

        p1.name();
        p2.name();
    }
}
