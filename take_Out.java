import java.io.*;
import java.util.Iterator;
import java.util.Scanner;


class LinkedList implements Iterable{

    public class Node {
        public int data;
        public Node next = null;

        public Node(int value) {
            this.data = value;
        }
    }
    private Node first=null;
    private Node current=null;

    public void add(int value){
        Node newNode=new Node(value);
        if(first==null){
            first=newNode;
            current=newNode;
        }else{
            current.next=newNode;
            current=newNode;
        }
    }

    public void display(){
        Node node=first;
        while(node!=null){
            int value=node.data;
            System.out.println(value);
            node=node.next;
        }
    }

    public Iterator iterator() {
        return new Iterator() {
            Node node=first;
            public boolean hasNext() {
                return node!=null;
            }

            public Object next() {
                int value=node.data;
                node=node.next;
                return value;
            }
        };
    }
}
class student{
    Scanner s=new Scanner(System.in);
    private String id;
    private String tel;

    public student(String id ,String tel){
        this.id=id;
        this.tel=tel;
    }

    public String getId() {
        this.id=s.next();
        return id;
    }

    public String getTel() {
        this.tel=s.next();
        return tel;
    }
}

public class take_Out {

    public void clean() {
        try {
            String os = System.getProperty("os.name");
            if (os.contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                System.out.println("\033c");
            }
        } catch (Exception exception) {
        }
    }

    public void putin() throws IOException {
        logol();
        System.out.println("");
        System.out.println("----------------------------- 外 卖 存 放 -----------------------------------");
        String id = null;
        String tel = null;
        Scanner a = new Scanner(System.in);
        int num = (int) (Math.random() * 1000 + 1000);
        String s = String.valueOf(num);
        student stu = new student(id, tel);
        System.out.println("__________________________");
        System.out.println("|请输入学生用户名：");
        id=stu.getId();
        System.out.println("__________________________");
        System.out.println("|请输入学生电话号码：");
        tel=stu.getTel();
        File file = new File("Take_Out.txt");
        BufferedWriter writer = new BufferedWriter(new FileWriter(file, true));
        writer.write(id+ "\t" + tel + "\t" + s +"\t"+"0"+ "\r\n");
        writer.close();
        System.out.println("-----外卖已成功存入！祝您生活愉快！(返回请输入“0”，还需送餐请输入“1”)-----");
        linenum();
        int i = 2;
        while (i != 0&&i!=1) {
            i = a.nextInt();
            clean();
        }
        if(i==1){
            putin();
        }
    }

    public void _putin() throws IOException {
        logol();
        System.out.println("");
        System.out.println("------------------------------ 外 卖 存 放 -----------------------------------");
        String id = null;
        String tel = null;
        Scanner a = new Scanner(System.in);
        int num = (int) (Math.random() * 1000 + 1000);
        String s = String.valueOf(num);
        student stu = new student(id, tel);
        System.out.println("__________________________");
        System.out.println("|请输入学生用户名：");
        id=stu.getId();
        System.out.println("__________________________");
        System.out.println("|请输入学生电话号码：");
        tel=stu.getTel();
        File file = new File("Take_Out.txt");
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));
        writer.write(id+ "\t" + tel + "\t" + s +"\t"+"0"+ "\r\n");
        writer.close();
        System.out.println("-----外卖已成功存入！祝您生活愉快！(返回请输入“0”，还需送餐请输入“1”)-----");
        linenum();
        int i = 2;
        while (i != 0&&i!=1) {
            i = a.nextInt();
            clean();
        }
        if(i==1){
            putin();
        }
    }

    public void putout() throws IOException {
        logol();
        System.out.println("");
        System.out.println("----------------------------- 外 卖 自 提 -----------------------------------");
        LinkedList list = new LinkedList();
        Scanner s = new Scanner(System.in);
        System.out.println("__________________________");
        System.out.println("|请输入取餐码：");
        String i = s.next();
        String line = null;
        String[] name=new String[line()];
        File file = new File("Take_Out.txt");
        BufferedReader reader=new BufferedReader(new FileReader(file));
        int w;
        int n=0;
        while ((line = reader.readLine()) != null) {
            String[] str=line.split("\\s+");
            w=0;
            for(String k:str){
                w++;
                if(w!=1&&w!=4) {
                    list.add(Integer.parseInt(k));
                }else if(w==1){
                    name[n]=k;
                    n++;
                }
            }
        }
        int pd=0;
        int cnt=0;
        for(Object pw:list){
            cnt++;
            if(cnt%2==0) {
                if (i.equals(String.valueOf((int)pw))) {
                    System.out.println("-----请取出您的外卖，祝您用餐愉快！(返回请输入“0”，还需取餐请输入“1”)-----\n");
                    reader.close();
                    delete(list,cnt,name);
                    pd = 1;
                    linenum();
                    break;
                }
            }
        }
        if (pd==0) {
            System.out.println("-----您的取餐码有误！(返回请输入“0”，取餐请输入“1”)-----\n");
            reader.close();
        }
        int p = 2;
        while (p != 0 && p != 1) {
            p = s.nextInt();
            clean();
        }
        if (p == 1) {
            putout();
        }
    }

    public void helptake() throws  IOException{
        logol();
        System.out.println("");
        System.out.println("----------------------------- 外 卖 代 取 -----------------------------------");
        LinkedList _list = new LinkedList();
        Scanner _s = new Scanner(System.in);
        System.out.println("__________________________");
        System.out.println("|请输入用餐人用户名：");
        String id=_s.nextLine();
        String line = null;
        int linenum=line();
        String[] name=new String[linenum];
        File file = new File("Take_Out.txt");
        BufferedReader reader=new BufferedReader(new FileReader(file));
        int w;
        int n=0;
        while ((line = reader.readLine()) != null) {
            String[] str=line.split("\\s+");
            w=0;
            for(String k:str){
                w++;
                if(w!=1&&w!=4) {
                    _list.add(Integer.parseInt(k));
                }else if(w==1){
                    name[n]=k;
                    n++;
                }
            }
        }
        int y=0;
        for(int x=0;x<linenum;x++){
            if(id.equals(name[x])){
                y=1;
                break;
            }
        }
        if(y==0){
            System.out.println("-----您输入的用餐人信息有误！(返回请输入“0”，代取请输入“1”)-----\n");
        }else {
            System.out.println("__________________________");
            System.out.println("|请输入用餐人取餐码：");
            String i = _s.next();
            int pd = 0;
            int cnt = 0;
            for (Object pw : _list) {
                cnt++;
                if (cnt % 2 == 0) {
                    if (i.equals(String.valueOf((int) pw))) {
                        if (id.equals(name[(cnt / 2) -1])) {
                            System.out.println("-----请取出用餐人的外卖，祝您生活愉快！(返回请输入“0”，还需代取请输入“1”)-----\n");
                            reader.close();
                            delete(_list,cnt,name);
                            pd = 1;
                            linenum();
                            break;
                        } else {
                            pd=1;
                            System.out.println("-----您输入的取餐码非该用餐人的取餐码！(返回请输入“0”，还需代取请输入“1”)-----\n");
                        }
                    }
                }
            }
            if (pd == 0) {
                System.out.println("-----您输入的取餐码有误！(返回请输入“0”，代取请输入“1”)-----\n");
                reader.close();
            }
        }
        int p = 2;
        while (p != 0 && p != 1) {
            p = _s.nextInt();
            clean();
        }
        if (p == 1) {
            helptake();
        }
    }

    public int line() throws IOException {
        BufferedReader reader=new BufferedReader(new FileReader("Take_Out.txt"));
        int cnt=0;
        while((reader.readLine())!=null){
            cnt++;
        }
        reader.close();
        return cnt;
    }

    public void linenum() throws IOException {
        int cnt;
        cnt=line();
        BufferedWriter writer=new BufferedWriter(new FileWriter("Line_number.txt"));
        String _cnt;
        _cnt=String.valueOf(cnt);
        writer.write(_cnt);
        writer.close();
    }

    public void delete(LinkedList list,int cnt,String[] name) throws IOException {
        BufferedWriter writer=new BufferedWriter(new FileWriter("Take_Out.txt"));
        int i=0;
        int j=0;
        String word=null;
        for(Object wr:list){
            j++;
            i++;
            word=String.valueOf((int)wr);
            if((j==(cnt-1))||(j==cnt)){
                continue;
            }
            if(j%2==0){
                writer.write(word+"\t"+"0"+"\r\n");
            }else{
                writer.write(name[(i/2)]+"\t"+word+"\t");
            }
        }
        writer.close();
    }
    
    public void logol(){
        System.out.println("|*---------------------------------------------------------------------------------------------------*|");
        System.out.println("|*|                 T A K E - O U T     M A N A G E M E N T     S Y S T E M                         |*|");
        System.out.println("|*---------------------------------------------------------------------------------------------------*|");
    }

    public void run() throws IOException {
        clean();
        System.out.println("|------------------------------------------   U   E   S   T   C  -----------------------------------------------------|");
        System.out.println("");
        System.out.println("      ___________________________________________________________________________________________________________");
        System.out.println("      |*________________________________________________________________________________________________________*|");
        System.out.println("      |*|                                                                                                      |*|");
        System.out.println("      |*|                                                                                                      |*|");
        System.out.println("      |*|   ************     ***       *      *    ********               *********   *        *  ************ |*|");
        System.out.println("      |*|        *        **     **    *     *    *                      *         *  *        *        *      |*|");
        System.out.println("      |*|        *       *         *   *    *     *                      *         *  *        *        *      |*|");
        System.out.println("      |*|        *       *         *   *   *      *                      *         *  *        *        *      |*|");
        System.out.println("      |*|        *       *         *   * *        *********   ********   *         *  *        *        *      |*|");
        System.out.println("      |*|        *       ***********   *   *      *                      *         *  *        *        *      |*|");
        System.out.println("      |*|        *       *         *   *     *    *                      *         *  *        *        *      |*|");
        System.out.println("      |*|        *       *         *   *       *  *                      *         *   *      *         *      |*|");
        System.out.println("      |*|        *       *         *   *        *  ********               *********     ******          *      |*|");
        System.out.println("      |*|                                                                                                      |*|");
        System.out.println("      |*|                      T A K E - O U T     M A N A G E M E N T     S Y S T E M                         |*|");
        System.out.println("      |*|                                                                                                      |*|");
        System.out.println("      |*|                                         ( 点 击 任 意 键 进 入)                                      |*|");
        System.out.println("      |*|______________________________________________________________________________________________________|*|");
        System.out.println("      |*________________________________________________________________________________________________________*|");
        System.out.println("");
        System.out.println("      #外卖管理系统注意事项：");
        System.out.println("               1.此为外卖存放与提取的管理系统");
        System.out.println("               2.外卖员存放外卖时，输入学生的用户名与电话号码后即可提取外卖");
        System.out.println("               3.学生提取外卖时，输入取餐码后即可提取外卖");
        System.out.println("               4.若是代取餐，需输入手机端收到的用餐人的取餐码");
        System.out.println("               5.请勿偷取他人外卖！！！");
        System.out.println("");
        System.out.println("|-------------------------------------------------- 祝 您 用 餐 愉 快 --------------------------------------------------|");
        Scanner input = new Scanner (System.in);
        String str = input.next ();
        clean();
        Scanner s = new Scanner(System.in);
        int i = 0;
        while (i != 4) {
            System.out.println("|*-----------------------------------------------------------------------------------------------------*|");
            System.out.println("|*|                    T A K E - O U T     M A N A G E M E N T     S Y S T E M                        |*|");
            System.out.println("|*-----------------------------------------------------------------------------------------------------*|");
            System.out.println("");
            System.out.println("\t\t\t*****************外  卖  管  理  系  统 *****************\t");
            System.out.println("");
            System.out.println("\t\t\t" + "________________________________________________________" + "\t");
            System.out.println("\t\t\t" + "|\t\t\t"+ "1. 送  外  卖" + "\t\t\t|" + "\t");
            System.out.println("\t\t\t" + "|_______________________________________________________|" + "\t");
            System.out.println("\t\t\t" + "|\t\t\t" + "2. 取  外  卖" + "\t\t\t|" + "\t");
            System.out.println("\t\t\t" + "|_______________________________________________________|" + "\t");
            System.out.println("\t\t\t" + "|\t\t\t" + "3.  代    取  " + "\t\t\t|" + "\t");
            System.out.println("\t\t\t" + "|_______________________________________________________|" + "\t");
            System.out.println("\t\t\t" + "|\t\t\t" + "4.  退    出  " + "\t\t\t|" + "\t");
            System.out.println("\t\t\t" + "|_______________________________________________________|" + "\t");
            System.out.println("");
            System.out.println("_________________________________________________");
            System.out.print("请输入操作：");
            i = s.nextInt();
            clean();
            linenum();
            switch (i) {
                case 1:
                    if(line()==0){
                        _putin();
                    }else{
                        putin();
                    }
                    break;
                case 2:
                    putout();
                    break;
                case 3:
                    helptake();
                    break;
                case 4:
                    System.out.println("\t********************已退出！********************\t");
                    break;
                default:
                    System.out.println("您输入的指令有误！请再次输入！");
                    break;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        take_Out to = new take_Out();
        to.run();
    }
}
