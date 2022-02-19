#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,l,rank[200];
    float I[200][200],T[200][200];
    float Age[200],Sexx[200],Steroid[200],Antivirals[200],Fatique[200],Malaise[200],Arexia[200],Big[200],Firm[200],Spleen[200],Speid[200],Ascit[200],Varices[200],Sex[200],Bilir[200],
    a,Alk[200],Sgot[200],Albumin[200],Protime[200],Histology[200],Class[200],totalerror,gini[200],giniA[200],giniB[200],JumlahawalNO[100], JumlahawalYES[100],No[200],Yes[200],JumlahakhirNO[100], JumlahakhirYES[100];
    float Jumlahnono=0,
        Jumlahnoyes=0,
        Jumlahyesno=0,
        Jumlahyesyes=0;
    freopen("inputdua.txt","r",stdin);//if You want to notepad , with name input.txt //data set
    for(i = 1 ; i <=80; i++ )
    {
        for(j=1; j<=20; j++)
        {
            scanf("%f", &I[i][j]);
            //printf("I[%d][%d]=%f\n",i,j,I[i][j]);
        }
    }

    freopen("testingsatu.txt","r",stdin);//if You want to notepad , with name input.txt //datalearning
    for(i = 1 ; i <=155; i++ )
    {
        for(j=1; j<=19; j++)
        {
            scanf("%f", &T[i][j]);
            //printf("T[%d][%d]=%f\n",i,j,T[i][j]);
        }
    }

    //Split dengan metode Gini Index
    for(i=1; i<=79; i++)
    {
        printf("i=%d\n",i);
        JumlahawalNO[i]=0;
        JumlahawalYES[i]=0;
        for(j=1; j<=i; j++)
        {
            if(I[j][20]==0)
            {
                No[j]=1;
                JumlahawalNO[i]= JumlahawalNO[i] + No[j];
            }
            else if(I[j][20]==1)
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
             if(I[j][20]==0)
            {
                No[j]=1;
                JumlahakhirNO[i]= JumlahakhirNO[i] + No[j];
            }
            else if(I[j][20]==1)
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

    for(i=1; i<=80; i++)
    {
        if(rank[i]==1)
        {
            for(j=1;j<=i;j++)
            {
                I[j][1]=0;
                I[j][14]=0;
                I[j][15]=0;
                I[j][16]=0;
                I[j][17]=0;
                I[j][18]=0;
            }
            for(j=i+1;j<=80;j++)
            {
                I[j][1]=1;
                I[j][14]=1;
                I[j][15]=1;
                I[j][16]=1;
                I[j][17]=1;
                I[j][18]=1;
            }
        }
    }

    float nono[200],noyes[200],yesno[200],yesyes[200];
    float q[40][40],E[200];
    for(i=1; i<=19; i++) //attribute/kolom
    {
        printf("i=%d\n",i);
        Jumlahnono=0;
        Jumlahnoyes=0;
        Jumlahyesno=0;
        Jumlahyesyes=0;
        for(j=1; j<=80; j++) //baris
        {
            if(I[j][i]==0&&I[j][20]==0)
            {
                nono[i]=1;
                Jumlahnono=Jumlahnono+nono[i];
            }
            else if(I[j][i]==0&&I[j][20]==1)
            {
                noyes[i]=1;
                Jumlahnoyes=Jumlahnoyes+noyes[i];
            }
            else if(I[j][i]==1&&I[j][20]==0)
            {
                yesno[i]=1;
                Jumlahyesno=Jumlahyesno+yesno[i];
            }
            else if(I[j][i]==1&&I[j][20]==1)
            {
                yesyes[i]=1;
                Jumlahyesyes=Jumlahyesyes+yesyes[i];
            }
        }
    printf("%f %f %f %f\n",Jumlahnono,Jumlahnoyes,Jumlahyesno,Jumlahyesyes);
    q[1][i]=-(Jumlahnono/(Jumlahnono+Jumlahnoyes))*(log10(Jumlahnono/(Jumlahnono+Jumlahnoyes)))/(log10(2))-(Jumlahnoyes/(Jumlahnoyes+Jumlahnono))*(log10(Jumlahnoyes/(Jumlahnono+Jumlahnoyes)))/(log10(2));
    if(Jumlahnono==0||Jumlahnoyes==0) //if digunakan supaya nilai lognya gak error. maka hasil q nya di groundkan
    {
        q[1][i]=0;
    }
    q[2][i]=-(Jumlahyesyes/(Jumlahyesyes+Jumlahyesno))*(log10(Jumlahyesyes/(Jumlahyesyes+Jumlahyesno)))/(log10(2))-(Jumlahyesno/(Jumlahyesno+Jumlahyesyes))*(log10(Jumlahyesno/(Jumlahyesyes+Jumlahyesno)))/(log10(2));
    if(Jumlahyesyes==0||Jumlahyesno==0) //if digunakan supaya nilai lognya gak error. maka hasil q nya di groundkan
    {
        q[2][i]=0;
    }
    E[i]=((Jumlahnono+Jumlahnoyes)*q[1][i]+(Jumlahyesno+Jumlahyesyes)*q[2][i])/(Jumlahnono+Jumlahnoyes+Jumlahyesno+Jumlahyesyes);
    printf("%f %f %f\n",q[1][i],q[2][i],E[i]);
    }

    printf("\nNo\t\t Nilai Ujian\t\t Rangking\n");
    //Perangkingan entropy
    for(i=1; i<=19; i++)
    {
        rank[i]=1;
        for(int b=1; b<=19; b++)
        {
            if(E[b]<E[i])
            {
                rank[i]++;
            }
        }
    printf("%d\t\t%f\t\t %d\n",i,E[i], rank[i]);
    }
    printf("\n\n");
    for(i=1; i<=19; i++)
    {
        for(j=i+1;j<=19;j++)
        {
            if(rank[i]==rank[j])
            {
                rank[j]++;
            }
        }
        printf("%d\t\t%f\t\t %d\n",i,E[i], rank[i]);
    }
/*
    l=1;
    for(i=1; i<=19; i++)
    {
        if(rank[i]==l++)
        {
            printf("Rank - %d\n",l);
            for(j=1; j<=80; j++)
            {
                if(I[j][i]==0)
                {
                    printf("0\t");
                    if(I[i][20]!=0)
                    {
                        printf("YES");
                    }
                    else if(I[i][20]!=1)
                    {
                        printf("NO");
                    }
                }
                else if(I[j][i]==1)
                {
                    printf("1\t");
                    if(I[i][20]!=0)
                    {
                        printf("YES");
                    }
                    else if(I[i][20]!=1)
                    {
                        printf("NO");
                    }
                }
            }
        }
    }
*/

    for(i=1; i<=19; i++) //rank
    {
        for(j=1; j<=19; j++) //kolom/attribute
        {
            if(rank[j]==1)
            {
                //printf("Attribute-%d\n",j);
                {
                    for(l=1; l<=155; l++)
                    {
                        if(T[l][j]==0)
                        {
                            if(rank[j]==19)
                            {
                                kelas[l][20]=
                                if(kelas[l][20]=
                            }
                        }
                        else if(T[l][j]==1)
                        {

                        }
                    }
                }
            }
        }
    }


}
