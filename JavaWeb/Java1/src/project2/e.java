package project2;

public class e {
    public static void main(String[] args) {

    }

    public boolean Login(user u) {
        if (u.name == "12345")
            return true;
        else
            return false;
    }
}

class user {
    public String name;
    public String sss;
}