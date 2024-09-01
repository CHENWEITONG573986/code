package project2;

public class d {
    public static void main(String[] args) {
        System.out.println(City.BEIJIN.name);
        System.out.println(MyCity.BEIJIN.name);
    }
}

class MyCity {
    public String name;
    public int code;
    private MyCity(String name, int code) {
        this.name = name;
        this.code = code;
    }
    public static final MyCity BEIJIN = new MyCity("北京", 1001);
}

enum City {
    BEIJIN("北京", 1001), SHANGHAI("上海", 1002);

    City(String name, int code) {
        this.name = name;
        this.code = code;
    }

    public String name;
    public int code;
}
