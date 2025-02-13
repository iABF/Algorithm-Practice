package lab2;
import java.util.*;
import java.util.regex.*;
import java.math.*;
public class Mynum 
{
	private static final int BYTE=1,SHORT=2,CHAR=3,INTEGER=4,LONG=5,FLOAT=6,DOUBLE=7;
	private static int getOpLevel(char op)
	{
		if(op=='+'||op=='-')return 1;
		if(op=='*'||op=='/'||op=='%')return 2;
		return 0;
	}
	private int level;
	private Number value;
	private Mynum() {}
	private Mynum(Number x){level=getNumberLevel(x);value=x;}
	private Mynum(String ss)
	{
		if(ss.contains(".")) {level=FLOAT;value=Float.valueOf(ss);}
		else {level=INTEGER;value=Integer.valueOf(ss);}
	}
	private Mynum(int lv,boolean flag){if(flag){level=lv;value=null;}}
	private class Cbn
	{
		Mynum num;
		char op;
		public boolean isnum(){if(num==null)return false;else return true;}
		Cbn(Mynum n){num=n;op=0;}
		Cbn(char c){num=null;op=c;}
	}
	private int getNumberLevel(Number x)
	{
		Class c=x.getClass();
		if(c==Byte.class)return BYTE;
		else if(c==Short.class)return SHORT;
		else if(c==Character.class)return INTEGER;
		else if(c==Integer.class)return INTEGER;
		else if(c==Long.class)return LONG;
		else if(c==Float.class)return FLOAT;
		else if(c==Double.class)return DOUBLE;
		return 0;
	}
	private int getLevel() {return level;}
	private Number getValue() {return value;}
	private static Mynum plus(Mynum a,Mynum b)
	{
		int maxlevel=a.level>b.level?a.level:b.level;
		switch(maxlevel)
		{
		case BYTE:return new Mynum((Number)(a.value.byteValue()+b.value.byteValue()));
		case SHORT:return new Mynum((Number)(a.value.shortValue()+b.value.shortValue()));
		case CHAR:
		case INTEGER:return new Mynum((Number)(a.value.intValue()+b.value.intValue()));
		case LONG:return new Mynum((Number)(a.value.longValue()+b.value.longValue()));
		case FLOAT:return new Mynum((Number)(a.value.floatValue()+b.value.floatValue()));
		case DOUBLE:return new Mynum((Number)(a.value.doubleValue()+b.value.doubleValue()));
		}
		return a;
	}
	private static Mynum minus(Mynum a,Mynum b)
	{
		int maxlevel=a.level>b.level?a.level:b.level;
		switch(maxlevel)
		{
		case BYTE:return new Mynum((Number)(a.value.byteValue()-b.value.byteValue()));
		case SHORT:return new Mynum((Number)(a.value.shortValue()-b.value.shortValue()));
		case CHAR:
		case INTEGER:return new Mynum((Number)(a.value.intValue()-b.value.intValue()));
		case LONG:return new Mynum((Number)(a.value.longValue()-b.value.longValue()));
		case FLOAT:return new Mynum((Number)(a.value.floatValue()-b.value.floatValue()));
		case DOUBLE:return new Mynum((Number)(a.value.doubleValue()-b.value.doubleValue()));
		}
		return a;
	}
	private static Mynum multiply(Mynum a,Mynum b)
	{
		int maxlevel=a.level>b.level?a.level:b.level;
		switch(maxlevel)
		{
		case BYTE:return new Mynum((Number)(a.value.byteValue()*b.value.byteValue()));
		case SHORT:return new Mynum((Number)(a.value.shortValue()*b.value.shortValue()));
		case CHAR:
		case INTEGER:return new Mynum((Number)(a.value.intValue()*b.value.intValue()));
		case LONG:return new Mynum((Number)(a.value.longValue()*b.value.longValue()));
		case FLOAT:return new Mynum((Number)(a.value.floatValue()*b.value.floatValue()));
		case DOUBLE:return new Mynum((Number)(a.value.doubleValue()*b.value.doubleValue()));
		}
		return a;
	}
	private static Mynum divide(Mynum a,Mynum b)
	{
		int maxlevel=a.level>b.level?a.level:b.level;
		switch(maxlevel)
		{
		case BYTE:return new Mynum((Number)(a.value.byteValue()/b.value.byteValue()));
		case SHORT:return new Mynum((Number)(a.value.shortValue()/b.value.shortValue()));
		case CHAR:
		case INTEGER:return new Mynum((Number)(a.value.intValue()/b.value.intValue()));
		case LONG:return new Mynum((Number)(a.value.longValue()/b.value.longValue()));
		case FLOAT:return new Mynum((Number)(a.value.floatValue()/b.value.floatValue()));
		case DOUBLE:return new Mynum((Number)(a.value.doubleValue()/b.value.doubleValue()));
		}
		return a;
	}
	private static Mynum remainder(Mynum a,Mynum b)
	{
		int maxlevel=a.level>b.level?a.level:b.level;
		switch(maxlevel)
		{
		case BYTE:return new Mynum((Number)(a.value.byteValue()%b.value.byteValue()));
		case SHORT:return new Mynum((Number)(a.value.shortValue()%b.value.shortValue()));
		case CHAR:
		case INTEGER:return new Mynum((Number)(a.value.intValue()%b.value.intValue()));
		case LONG:return new Mynum((Number)(a.value.longValue()%b.value.longValue()));
		case FLOAT:return new Mynum((Number)(a.value.floatValue()%b.value.floatValue()));
		case DOUBLE:return new Mynum((Number)(a.value.doubleValue()%b.value.doubleValue()));
		}
		return a;
	}
	private static class ErrorExpression extends Exception{public ErrorExpression() {}}
	private static class VariableUndefined extends Exception{public VariableUndefined() {}}
	private static class VariableUnassigned extends Exception{public VariableUnassigned() {}}
	private Mynum calculate(String oristr,Map<String,Mynum>mp)throws EmptyStackException,ErrorExpression,VariableUndefined,VariableUnassigned
	{
		Vector<Cbn>Postfix=new Vector<Cbn>();
		Stack<Character>stack1=new Stack<Character>();
		Stack<Mynum>stack2=new Stack<Mynum>();
		Pattern numdata=Pattern.compile("[0-9]{1,}([.][0-9]{1,}){0,1}");
		Pattern chardata=Pattern.compile("[*+-/%]");
		Pattern namedata=Pattern.compile("[a-zA-Z_][0-9a-zA-Z_]*");
		Pattern bracketdata=Pattern.compile("[()]");
		for(int i=0;i<oristr.length();i++)
		{
			Matcher NumMth=numdata.matcher(oristr.substring(i).trim());
			Matcher CharMth=chardata.matcher(oristr.substring(i).trim());
			Matcher NameMth=namedata.matcher(oristr.substring(i).trim());
			Matcher BrMth=bracketdata.matcher(oristr.substring(i).trim());
			if(NumMth.find(0)&&oristr.substring(i).startsWith(NumMth.group()))//the substring starts with a number(integer or float)
			{
				Postfix.add(new Cbn(new Mynum(NumMth.group())));
				i+=NumMth.end()-1;
			}
			else if(CharMth.find(0)&&oristr.substring(i).startsWith(CharMth.group()))//the substring starts with a operator(+-*/%)
			{
				char op=CharMth.group().charAt(0);
				while(!stack1.empty()&&getOpLevel(stack1.peek())>=getOpLevel(op))Postfix.add(new Cbn(stack1.pop()));
				stack1.push(op);
			}
			else if(NameMth.find(0)&&oristr.substring(i).startsWith(NameMth.group()))//the substring starts with an Argument_Name
			{
				if(!mp.containsKey(NameMth.group()))throw new VariableUndefined();
				else Postfix.add(new Cbn(mp.get(NameMth.group())));
				i+=NameMth.end()-1;
			}
			else if(BrMth.find(0)&&oristr.substring(i).startsWith(BrMth.group()))//the substring starts with a bracket
			{
				if(BrMth.group().equals("("))stack1.push('(');
				else
				{
					while(stack1.peek()!='(')Postfix.add(new Cbn(stack1.pop()));
					stack1.pop();
				}
			}
			else throw new ErrorExpression();//the substring starts with trash
		}
		while(!stack1.empty())//if finished reading oristr, add all ops into Postfix
		{
			if(stack1.peek()!='(')Postfix.add(new Cbn(stack1.pop()));
			else throw new ErrorExpression();
		}
		for(int i=0;i<Postfix.size();i++)//now the Postfix is completed, start calculating
		{
			if(Postfix.elementAt(i).isnum())stack2.push(Postfix.elementAt(i).num);
			else
			{
				char op=Postfix.elementAt(i).op;
				Mynum rn=stack2.pop();
				Mynum ln=stack2.pop();
				if(rn.getValue()==null||ln.getValue()==null)throw new VariableUnassigned();
				if(op=='+')stack2.push(Mynum.plus(ln, rn));
				else if(op=='-')stack2.push(Mynum.minus(ln, rn));
				else if(op=='*')stack2.push(Mynum.multiply(ln, rn));
				else if(op=='/')stack2.push(Mynum.divide(ln, rn));
				else if(op=='%')stack2.push(Mynum.remainder(ln, rn));
			}
		}
		if(stack2.size()!=1)throw new ErrorExpression();
		return stack2.pop();
	}
	public static void main(String[] args) 
	{
		Map<String,Mynum>mp=new HashMap<String,Mynum>();
		Scanner sc=new Scanner(System.in);
		try
		{
			while(sc.hasNextLine())
			{
				String[] s=sc.nextLine().trim().split(";");
				for(int i=0;i<s.length;i++)
				{
					if(s[i].contains("?"))//if this needs a answer: CALCULATION
					{
						s[i]=s[i].substring(0, s[i].length()-2).trim();
						int brnum=0;
						for(int j=0;j<s[i].length();j++)
						{
							if(s[i].charAt(j)=='(')brnum++;
							else if(s[i].charAt(j)==')')brnum--;
							if(brnum<0)throw new ErrorExpression();
						}
						if(brnum!=0)throw new ErrorExpression();
						Mynum ans=new Mynum().calculate(s[i], mp);
						if(ans.getLevel()>LONG)System.out.printf("%.2f\n", ans.getValue());
						else System.out.printf("%d\n",ans.getValue());
					}
					else//ASSIGNMENT or DECLARATION
					{
						String[] f=s[i].split(" |=");
						if(f[1].matches("[a-zA-Z_][0-9a-zA-Z_]*"))//f[1] is a word, which must be a Argument_Name ({float word;} or {float word=1243;})
						{
							if(f[0].equals("int"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Integer.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(INTEGER,true));
							}
							else if(f[0].equals("byte"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Byte.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(BYTE,true));
							}
							else if(f[0].equals("short"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Short.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(SHORT,true));
							}
							else if(f[0].equals("char"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Integer.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(INTEGER,true));
							}
							else if(f[0].equals("long"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Long.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(LONG,true));
							}
							else if(f[0].equals("float"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Float.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(FLOAT,true));
							}
							else if(f[0].equals("double"))
							{
								if(s[i].contains("="))mp.put(f[1], new Mynum((Number)(Double.valueOf(f[2]))));
								else mp.put(f[1], new Mynum(DOUBLE,true));
							}
							else throw new ErrorExpression();
						}
						else//f[1] is not a word, which means f[1] is a number(or error), must be a ASSIGNMENT (word=1243;)
						{
							if(!f[0].matches("[a-zA-Z_][0-9a-zA-Z_]*")||!s[i].contains("="))throw new ErrorExpression();
							if(!mp.containsKey(f[0]))throw new VariableUndefined();
							if(mp.get(f[0]).getLevel()==INTEGER)mp.put(f[0], new Mynum((Number)(Integer.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==BYTE)mp.put(f[0], new Mynum((Number)(Byte.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==SHORT)mp.put(f[0], new Mynum((Number)(Short.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==CHAR)mp.put(f[0], new Mynum((Number)(Integer.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==LONG)mp.put(f[0], new Mynum((Number)(Long.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==FLOAT)mp.put(f[0], new Mynum((Number)(Float.valueOf(f[1]))));
							else if(mp.get(f[0]).getLevel()==DOUBLE)mp.put(f[0], new Mynum((Number)(Double.valueOf(f[1]))));
							else throw new ErrorExpression();
						}
					}
				}
			}
		}
		catch(EmptyStackException|NumberFormatException|ErrorExpression e) {System.out.println("wrong - error expression");}
		catch (VariableUndefined e) {System.out.println("wrong - variable undefined");}
		catch (VariableUnassigned e){System.out.println("wrong - variable unassigned");}
	}
}