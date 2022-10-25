package lab3;
import java.util.*;
import java.util.regex.*;
import java.math.*;
public class CalExp
{
	CalExp(){}
	private class Cbn
	{
		BigDecimal num;
		char op;
		boolean isnum() {if(num==null)return false;else return true;}
		Cbn(BigDecimal d){num=d;op=0;}
		Cbn(char c){num=null;op=c;}
	}
	private static int getOpLevel(char op)
	{
		if(op=='+'||op=='-')return 1;
		if(op=='*'||op=='/'||op=='%')return 2;
		return 0;
	}
	private BigDecimal calculate(String oristr)
	{
		Stack<Character>stack1=new Stack<Character>();
		Stack<BigDecimal>stack2=new Stack<BigDecimal>();
		Vector<Cbn>Postfix=new Vector<Cbn>();
		Pattern numdata=Pattern.compile("[0-9]{1,}([.][0-9]{1,}){0,1}"),chardata=Pattern.compile("[*+-/%]"),bracketdata=Pattern.compile("[()]");
		for(int i=0;i<oristr.length();i++)
		{
			Matcher NumMth=numdata.matcher(oristr.substring(i).trim()),CharMth=chardata.matcher(oristr.substring(i).trim()),BrMth=bracketdata.matcher(oristr.substring(i).trim());
			if(NumMth.find(0)&&oristr.substring(i).startsWith(NumMth.group()))
			{
				Postfix.add(new Cbn(new BigDecimal(NumMth.group())));
				i+=NumMth.end()-1;
			}
			else if(CharMth.find(0)&&oristr.substring(i).startsWith(CharMth.group()))
			{
				char op=CharMth.group().charAt(0);
				while(!stack1.empty()&&getOpLevel(stack1.peek())>=getOpLevel(op))Postfix.add(new Cbn(stack1.pop()));
				stack1.push(op);
			}
			else if(BrMth.find(0)&&oristr.substring(i).startsWith(BrMth.group()))
			{
				if(BrMth.group().equals("("))stack1.push('(');
				else
				{
					while(stack1.peek()!='(')Postfix.add(new Cbn(stack1.pop()));
					stack1.pop();
				}
			}
		}
		while(!stack1.empty())Postfix.add(new Cbn(stack1.pop()));
		for(int i=0;i<Postfix.size();i++)
		{
			if(Postfix.elementAt(i).isnum())stack2.push(Postfix.elementAt(i).num);
			else
			{
				char op=Postfix.elementAt(i).op;
				BigDecimal rn=stack2.pop();
				BigDecimal ln=stack2.pop();
				if(op=='+')stack2.push(ln.add(rn));
				else if(op=='-')stack2.push(ln.subtract(rn));
				else if(op=='*')stack2.push(ln.multiply(rn));
				else if(op=='/')stack2.push(ln.divide(rn));
				else if(op=='%')stack2.push(ln.remainder(rn));
			}
		}
		return stack2.pop();
	}
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine().trim();
		if(s.contains("="))s=s.substring(0,s.length()-1).trim();
		BigDecimal ans=new CalExp().calculate(s);
		if(ans.toString().contains("."))System.out.println(ans);
		else System.out.println(ans+".0");
	}
}
