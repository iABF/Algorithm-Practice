import java.lang.*;
import java.util.*;
public class DaiKuan {
    public static void main(String[] arg){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        int c=s.nextInt();
        Loan n=new ELoan(a,b);
        n.createplan(c);
        n.printPayPlan();
    }
}
class PayPlan {
    int number;
    double amount;
    double benjin;
}
abstract class Loan{
    double loanAmount;
    int months;
    double rate;
    PayPlan [] pp;
    Loan(int x,int y){
        loanAmount=x;
        months=y*12;
        if(y<=1) rate=4.35/100;
        else if(y<=5) rate=4.75/100;
        else rate=4.90/100;
        rate/=12;
        pp=new PayPlan[months+1];
    }
    abstract void createplan(int x);

    public void printPayPlan(){
        System.out.println("    本金      利息      总额");
        for(int i=1;i<=months;i++){
            System.out.println(pp[i].number+"   "+pp[i].benjin+" "+(pp[i].amount-pp[i].benjin)+" "+pp[i].amount);
        }
    }
}
class ELoan extends Loan{
    ELoan(int x,int y){
        super(x,y);
    }
    void createplan(int z){
        if(z==1){
            for(int i=1;i<=months;i++){
            	pp[i]=new PayPlan();
                pp[i].number=i;
                pp[i].amount=loanAmount*rate*Math.pow(1+rate, months)/(Math.pow(1+rate, months)-1);
                pp[i].benjin=loanAmount*rate*Math.pow(1+rate, i-1)/(Math.pow(1+rate, months)-1);
            }
        }
    }
}
