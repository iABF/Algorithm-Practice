import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Random;


class SellCD
{
	private int id;
	private int num;
	private String name;
	public int getnum() {return num;}
	public SellCD(int ID,String n)
	{
		id=ID;
		name=n;
		num=10;
	}
	@Override
	public String toString()
	{
		if(id<10)return "No."+id+" - ["+name+"]";
		else return "No."+"X"+" - ["+name+"]";
	}
	public void minus(int x) {num-=x;}
	public void fill() {num=10;}
}

class RentCD
{
	private int id;
	private String name;
	private boolean isrent=false;
	public boolean isRent() {return isrent;}
	public RentCD(int ID,String n)
	{
		id=ID;
		name=n;
		isrent=false;
	}
	@Override
	public String toString()
	{
		if(id<10)return "No."+id+" - ["+name+"]";
		else return "No."+"X"+" - ["+name+"]";
	}
	public void rent() {isrent=true;}
	public void back() {isrent=false;}
}
class RentThread extends Thread
{
	CDShop src;
	RentThread(CDShop cd,String nme)
	{
		super(nme);
		src=cd;
		try {Thread.sleep(new Random().nextInt(200));}
		catch (InterruptedException e) {e.printStackTrace();}
		this.start();
	}
	@Override
	public void run()
	{
		while(true)
		{
			try {Thread.sleep(new Random().nextInt(200));}//sleep outside synchronized
			catch (InterruptedException e) {e.printStackTrace();}
			int id=new Random().nextInt(10);
			synchronized(src.rentlist)
			{
				if(!src.rentlist.get(id).isRent())
				{
					System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Rent CD: "+src.rentlist.get(id).toString());
					src.rentlist.get(id).rent();
					src.rentlist.notifyAll();
					try {src.rentlist.wait(new Random().nextInt(100)+200);}
					catch (InterruptedException e) {e.printStackTrace();}
					System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Back CD: "+src.rentlist.get(id).toString());
					src.rentlist.get(id).back();
				}
				else
				{
					if(new Random().nextBoolean())//wait
					{
						System.out.println(this.getName()+": "+"No Goods to Rent: "+src.rentlist.get(id).toString()+". Wait.");
						try {src.rentlist.wait();}
						catch (InterruptedException e) {e.printStackTrace();}
						if(src.rentlist.get(id).isRent())System.out.println(this.getName()+": "+"Still no Goods to Rent: "+src.rentlist.get(id).toString()+" after Waiting. Cancelled.");//wait and failed
						else
						{
							System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Rent after Waiting: "+src.rentlist.get(id).toString());
							src.rentlist.get(id).rent();
							src.rentlist.notifyAll();
							try {src.rentlist.wait(new Random().nextInt(100)+200);}
							catch (InterruptedException e) {e.printStackTrace();}
							System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Back CD: "+src.rentlist.get(id).toString());
							src.rentlist.get(id).back();
						}
					}
					else System.out.println(this.getName()+": "+"Still no Goods to Rent: "+src.rentlist.get(id).toString()+". Cancelled.");//cancelled without waiting
				}
			}
		}
	}
}
class SellThread extends Thread
{
	CDShop src;
	SellThread(CDShop cd,String nme)
	{
		super(nme);
		src=cd;
		try {Thread.sleep(new Random().nextInt(200));}
		catch (InterruptedException e) {e.printStackTrace();}
		this.start();
	}
	@Override
	public void run()
	{
		while(true)
		{
			try {Thread.sleep(new Random().nextInt(200));}//sleep outside synchronized
			catch (InterruptedException e) {e.printStackTrace();}
			int id=new Random().nextInt(10);//the id to be sold(1~10)
			int num=new Random().nextInt(5)+1;//the number of CD_id to be sold(1~5)
			synchronized(src.selllist)
			{
				if(src.selllist.get(id).getnum()>=num)
				{
					System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Sold CD: "+src.selllist.get(id).toString()+"¡Á"+num);
					src.selllist.get(id).minus(num);
				}
				else
				{
					src.selllist.notifyAll();//especially wakes up the goodsin thread
					if(new Random().nextBoolean())//wait
					{
						System.out.println(this.getName()+": "+"No Goods to Sell: "+src.selllist.get(id).toString()+". Wait.");
						try {src.selllist.wait();}
						catch (InterruptedException e) {e.printStackTrace();}
						if(src.selllist.get(id).getnum()>=num)//wait and sold
						{
							System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Sold after Waiting: "+src.selllist.get(id).toString()+"¡Á"+num);
							src.selllist.get(id).minus(num);
						}
						else System.out.println(this.getName()+": "+"Still no Goods to Sell: "+src.selllist.get(id).toString()+" after Waiting. Cancelled.");//wait and failed
					}
					else System.out.println(this.getName()+": "+"No Goods to Sell: "+src.selllist.get(id).toString()+". Cancelled.");//cancelled without waiting
				}
			}
		}
	}
}
class StockThread extends Thread
{
	CDShop src;
	StockThread(CDShop cd,String nme)
	{
		super(nme);
		src=cd;
		this.start();
	}
	@Override
	public void run()
	{
		while(true)
		{
			synchronized(src.selllist)
			{
				System.out.println(this.getName()+": "+LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" Stock all CDs.");
				src.getinGoods();
				src.selllist.notifyAll();
				try {src.selllist.wait(1000);}
				catch (InterruptedException e) {e.printStackTrace();}
			}
		}
	}
}

class ControlThread extends Thread
{
	CDShop src;
	ControlThread(CDShop cd)
	{
		super();
		src=cd;
	}
	@Override
	public void run()
	{
		new StockThread(src,"¡öTHANOS ");
		new SellThread(src,"Baidu  ");
		new SellThread(src,"Alibaba");
		new SellThread(src,"Tencent");
		new SellThread(src,"Huawei ");
		new RentThread(src,"ofo    ");
		new RentThread(src,"Mobike ");
		new RentThread(src,"Hello  ");
		new RentThread(src,"CTrip  ");
	}
}

public class CDShop
{
	ArrayList<SellCD>selllist=new ArrayList<SellCD>(10);
	ArrayList<RentCD>rentlist=new ArrayList<RentCD>(10);
	CDShop()
	{
		selllist.add(new SellCD(1,"III-Arena"));
		selllist.add(new SellCD(2,"EZ4ENCE"));
		selllist.add(new SellCD(3,"FREE"));
		selllist.add(new SellCD(4,"Aggressive"));
		selllist.add(new SellCD(5,"Life's Not Out To Get You"));
		selllist.add(new SellCD(6,"The Good Youth"));
		selllist.add(new SellCD(7,"Java Havana Funkaloo"));
		selllist.add(new SellCD(8,"Disgusting"));
		selllist.add(new SellCD(9,"Sponge Fingerz"));
		selllist.add(new SellCD(10,"Lion's Mouth"));
		rentlist.add(new RentCD(1,"Invasion!"));
		rentlist.add(new RentCD(2,"Diamonds"));
		rentlist.add(new RentCD(3,"I Am"));
		rentlist.add(new RentCD(4,"The 8-Bit Kit"));
		rentlist.add(new RentCD(5,"II-Headshot"));
		rentlist.add(new RentCD(6,"Hazardous Environments"));
		rentlist.add(new RentCD(7,"Uber Blasto Phone"));
		rentlist.add(new RentCD(8,"MOLOTOV"));
		rentlist.add(new RentCD(9,"The Talos Principle"));
		rentlist.add(new RentCD(10,"Insurgency"));
	}
	public void getinGoods(){for(int i=0;i<10;i++)selllist.get(i).fill();}
	public static void main(String[] args)
	{
		try
		{
			FileOutputStream fs=new FileOutputStream(new File("output.txt"));
			PrintStream ps=new PrintStream(fs);
			System.setOut(ps);
		}
		catch (FileNotFoundException e) {e.printStackTrace();}
		CDShop src=new CDShop();
		ControlThread ctrl=new ControlThread(src);
		ctrl.setDaemon(true);
		ctrl.start();
		try {Thread.sleep(120000);}
		catch (InterruptedException e) {e.printStackTrace();}
	}
}
