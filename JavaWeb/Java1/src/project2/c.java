package project2;

public class c {
    public static void main(String[] args) {
        Computer C = new Computer();
        Light L1 = new Light();
        Light L2 = new Light();
        C.usb1 = L1;
        C.usb2 = L2;
        C.powerS();
    }
}

interface USB {

}

interface USBS extends USB {
    public void powerS();
}

interface USBR extends USB {
    public void powerR();
}

class Computer implements USBS {
    public USBR usb1;
    public USBR usb2;

    public void powerS() {
        System.out.println("电脑提供能源");
        usb1.powerR();
        usb2.powerR();
    }
}

class Light implements USBR {
    public void powerR() {
        System.out.println("电灯接受能源");
    }
}