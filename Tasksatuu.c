#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,l,rank[200];
    float Age[200],Sexx[200],Steroid[200],Antivirals[200],Fatique[200],Malaise[200],Arexia[200],Big[200],Firm[200],Spleen[200],Speid[200],Ascit[200],Varices[200],Sex[200],Bilir[200],
    a,Alk[200],Sgot[200],Albumin[200],Protime[200],Histology[200],Class[200],totalerror,gini[200],giniA[200],giniB[200],JumlahawalNO[100], JumlahawalYES[100],No[200],Yes[200],JumlahakhirNO[100], JumlahakhirYES[100];
    float Jumlahnono=0,
        Jumlahnoyes=0,
        Jumlahyesno=0,
        Jumlahyesyes=0;
    freopen("inputdua.txt","r",stdin);//if You want to notepad , with name input.txt
    for(i = 1 ; i <=80; i++ )
    {
        scanf("%f", &Age[i]);
        scanf("%f", &Sexx[i]);
        scanf("%f", &Steroid[i]);
        scanf("%f", &Antivirals[i]);
        scanf("%f", &Fatique[i]);
        scanf("%f", &Malaise[i]);
        scanf("%f", &Arexia[i]);
        scanf("%f", &Big[i]);
        scanf("%f", &Firm[i]);
        scanf("%f", &Spleen[i]);
        scanf("%f", &Speid[i]);
        scanf("%f", &Ascit[i]);
        scanf("%f", &Varices[i]);
        scanf("%f", &Bilir[i]);
        scanf("%f", &Alk[i]);
        scanf("%f", &Sgot[i]);
        scanf("%f", &Albumin[i]);
        scanf("%f", &Protime[i]);
        scanf("%f", &Histology[i]);
        scanf("%f", &Class[i]);
    }

    //Split dengan metode Gini Index
    for(i=1; i<=79; i++)
    {
        printf("i=%d\n",i);
        JumlahawalNO[i]=0;
        JumlahawalYES[i]=0;
        for(j=1; j<=i; j++)
        {
            if(Class[j]==0)
            {
                No[j]=1;
                JumlahawalNO[i]= JumlahawalNO[i] + No[j];
            }
            else if(Class[j]==1)
            {
                Yes[j]=1;
                JumlahawalYES[i]= JumlahawalYES[i] + Yes[j];
            }
        }
        printf("Jumlah awal NO = %f\n",JumlahawalNO[i]);
        printf("Jumlah awal YES = %f\n",JumlahawalYES[i]);
        JumlahakhirNO[i]=0;
        JumlahakhirYES[i]=0;
        for(j=i+1; j<=80; j++)
        {
             if(Class[j]==0)
            {
                No[j]=1;
                JumlahakhirNO[i]= JumlahakhirNO[i] + No[j];
            }
            else if(Class[j]==1)
            {
                Yes[j]=1;
                JumlahakhirYES[i]= JumlahakhirYES[i] + Yes[j];
            }
        }
        printf("Jumlah akhir NO = %f\n",JumlahakhirNO[i]);
        printf("Jumlah akhir YES = %f\n",JumlahakhirYES[i]);

        float k;
        k=i;
        a=k/80;
        giniA[i]=(1-(JumlahawalYES[i]/i)*(JumlahawalYES[i]/i)-(JumlahawalNO[i]/i)*(JumlahawalNO[i]/i));
        giniB[i]=1-(JumlahakhirYES[i]/(80-i))*(JumlahakhirYES[i]/(80-i))-(JumlahakhirNO[i]/(80-i))*(JumlahakhirNO[i]/(80-i));
        gini[i]=(k/80)*giniA[i]+((80-k)/80)*giniB[i];
        printf("%f %f %f\n",a,giniA[i],giniB[i]);
        printf("Gini[%d]=%f\n\n",i,gini[i]);
    }

    //SPLIT RANKING: dipilih nilai gini yg terendah/ ranking no 1.
    for(i=1; i<=79; i++)
    {
        rank[i]=1;
        for(int b=1; b<=79; b++)
        {
            if(gini[i]>gini[b])
            {
                rank[i]++;
            }
        }
    }
    printf("No\t\t Nilai Ujian\t\t Rangking\n");

    for(i=1; i<=79; i++)
    {
         printf("%d\t\t%f\t\t %d\n",i,gini[i], rank[i]);
    }

    for(i=1;i<=80;i++)
    {
        if(rank[i]==1)
        {
            for(j=i+1; j<=80; j++)
            {
                Age[j]=0;
                Bilir[j]=0;
                Alk[j]=0;
                Sgot[j]=0;
                Albumin[j]=0;
                Protime[j]=0;
            }
            for(j=i; j>=1; j--)
            {
                Age[j]=1;
                Bilir[j]=1;
                Alk[j]=1;
                Sgot[j]=1;
                Albumin[j]=1;
                Protime[j]=1;

            }
        }
    }
    /*
    for(i=1; i<=80; i++)
    {
        printf("Age[%d] = %f\n",i,Age[i]);
        printf("Bilir[%d] = %f\n",i,Bilir[i]);
        printf("Alk[%d] = %f\n",i,Alk[i]);
        printf("Sgot[%d] = %f\n",i,Sgot[i]);
        printf("Albumin[%d] = %f\n",i,Albumin[i]);
        printf("Protime[%d] = %f\n",i,Protime[i]);
    }
    */
    float nono[200],noyes[200],yesno[200],yesyes[200];
    Jumlahnono=0;
        Jumlahnoyes=0;
        Jumlahyesno=0;
        Jumlahyesyes=0;
    for(i=1; i<=80; i++)
    {
        if(Age[i]==0&&Class[i]==0)
        {
            nono[i]=1;
            Jumlahnono=Jumlahnono+nono[i];
        }
        else if(Age[i]==0&&Class[i]==1)
        {
            noyes[i]=1;
            Jumlahnoyes=Jumlahnoyes+noyes[i];
        }
        else if(Age[i]==1&&Class[i]==0)
        {
            yesno[i]=1;
            Jumlahyesno=Jumlahyesno+yesno[i];
        }
        else if(Age[i]==1&&Class[i]==1)
        {
            yesyes[i]=1;
            Jumlahyesyes=Jumlahyesyes+yesyes[i];
        }
    }
    printf("%f %f %f %f\n",Jumlahnono,Jumlahnoyes,Jumlahyesno,Jumlahyesyes);


}
