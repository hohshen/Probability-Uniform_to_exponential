#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double gen_exp(double lambda)
{
    /*
      y
      |
     F(x)=1-e^(-lx)
     F(F^(u))=u
     1-e^(-l*F^(u))=u
     e^(-l*F^(u))=1-u
     -l*F^(u)=ln(1-u)
     F^(u)=(-1/l)*ln(1-u)
       |               |
       x               y
       finish
    */
    double cons=(-1)/lambda;
    double y = (double) rand() / (RAND_MAX + 1.0);//���F����0~1���ü�
    double a=cons*(log(1-y));

    return a;
}
int main()
{
    int i;
    double	sample[100000];//�üƲ��ͫ�s���m
    double x;//��X�p
    int num=0;
    double F;
    srand(time(NULL));//���Ͷüƺؤl
    for(i=0; i<100000; i++)//���ͶüƦs�bsample
        sample[i]=gen_exp((double)1);

    printf("Input x: ");//��J�Dx��CDF
    scanf("%lf",&x);

    double sx[5]={1,2,3,4,5};
    double sa[5]={0.0}; //��ڹ����

    double su[5]={0.0}; //��ھ��v��
    su[0]=1-exp(-sx[0]);
    su[1]=1-exp(-sx[1]);
    su[2]=1-exp(-sx[2]);
    su[3]=1-exp(-sx[3]);
    su[4]=1-exp(-sx[4]);
    for(i=0; i<100000; i++)//�p�⦳�X��sample��X�p
    {
        if(sample[i]<=sx[0]){
            sa[0]++;
        }
        if(sample[i]<=sx[1]){
            sa[1]++;
        }
        if(sample[i]<=sx[2]){
            sa[2]++;
        }
        if(sample[i]<=sx[3]){
            sa[3]++;
        }
        if(sample[i]<=sx[4]){
            sa[4]++;
        }
        if(sample[i]<=x)
            num=num+1;
    }

    F=num/(double)100000;//��ڹ���X�����v  F^=�ƾǾ��v
    printf("number of sample<X:%d\n",num);
    printf("Output: %lf\n",F);
    maketable(sx,sa,su);
    return 0;
}
void maketable(double *sx,double *sa,double *su){

    printf("=================================================\n");
    printf(" X |%5lf|%5lf|%5lf|%5lf|%5lf|\n",sx[0],sx[1],sx[2],sx[3],sx[4]);
    printf("=================================================\n");
    //��ڹ����
    printf(" F^|%5lf|%5lf|%5lf|%5lf|%5lf|\n",sa[0]/(double)100000,sa[1]/(double)100000,sa[2]/(double)100000,sa[3]/(double)100000,sa[4]/(double)100000);
     //��ھ��v��
    printf(" F |%5lf|%5lf|%5lf|%5lf|%5lf|\n",su[0],su[1],su[2],su[3],su[4]);
    printf("=================================================\n");

    return 0;
}
