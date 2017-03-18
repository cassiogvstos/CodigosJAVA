#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no
{
	struct no *esq;
	int info;
	struct no *dir;
};

typedef struct no Lista;

void Cria_LDE(Lista **Inicio, Lista **Fim)
{
   *Inicio = NULL;
   *Fim = NULL;	
}

void Ins_Inicio(Lista **Inicio, Lista **Fim, int v)
{
	Lista *p;
	
	p = (Lista *)calloc(1, sizeof(Lista));
	p->info = v;
	p->esq = NULL;
	p->dir = *Inicio;
	if (*Inicio == NULL)
	   *Fim = p;
	else
	   (*Inicio)->esq = p;
	
	*Inicio = p;
}

void Ins_Fim(Lista **Inicio, Lista **Fim, int v)
{
	Lista *p;
	
	p = (Lista *)calloc(1, sizeof(Lista));
	p->info = v;
	p->dir = NULL;
	p->esq = *Fim;
	if (*Inicio == NULL)
	   *Inicio = p;
	else
	   (*Fim)->dir = p;
	   
	*Fim = p;
	
}

void Imprime(Lista *Inicio)
{
	Lista *p;
	
	p = Inicio;
	
	printf("\n\nNULL");
	while(p!=NULL)
	{
		printf("<--%d-->", p->info);
		p = p->dir;
	}
	printf("NULL\n");
}

int Rem_Inicio (Lista **Inicio, Lista **Fim, int *v)
{
	Lista *p;
	if (*Inicio!=NULL)
	{
		p=*Inicio;
		*Inicio= p->dir;
		if (p->dir==NULL)  // só existe 1 nó na lista
		   *Fim=NULL;
		else
		   (*Inicio)->esq=NULL;
		*v=p->info;
		free(p);
		return 1;
	}
	else return 0;
}

int Rem_Fim (Lista **Inicio, Lista **Fim, int *v)
{
	Lista *p;
	if (*Inicio!=NULL)
	{
		p=*Fim;
		*Fim= p->esq;
		if (p->esq==NULL)  // só existe 1 nó na lista
		   *Inicio=NULL;
		else
		   (*Fim)->dir=NULL;
		*v=p->info;
		free(p);
		return 1;
	}
	else return 0;
}

Lista * Consulta (Lista *Inicio, int v)
{
	Lista *p;
	p=Inicio;

	while((p!=NULL)&&(p->info != v))
		p = p->dir;

	return p;
}

void Ins_Depois(Lista *r, int v)
{
	Lista *p;

	p = (Lista *)calloc(1,sizeof(Lista));

	p->info = v;

	p->esq = r;
	p->dir = r->dir;

	r->dir->esq = p;
	r->dir = p;
}

void Rem_meio(Lista *r)
{
	r->esq->dir = r->dir;
	r->dir->esq = r->esq;

	free(r);
}

void Rem_ocor(Lista *Inicio, int v)
{
	Lista *p, Lista *r;
	p = Inicio;

}

main()
{
	Lista *Inicio, *Fim, *r;
	int op, val;
	
	Cria_LDE(&Inicio, &Fim);
	
	do
	{
		system("cls");
		puts("1 - Inserir no Inicio");
		puts("2 - Inserir no Fim");
		puts("3 - Imprimir a Lista");
		puts("4 - Remover no Inicio");
		puts("5 - Remover no Fim");
		puts("6 - Consultar valor na Lista");
		puts("7 - Inserir depois de valor");
		puts("8 - Remover do meio");
		puts("9 - Remover as ocorrencias repetidas");
		
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio, &Fim, val);
			        break;
			        
			case 2: printf("\nDigite o valor: ");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio, &Fim, val);
			        break;
			        
			case 3: if (Inicio == NULL)
			           printf("\nLista Vazia!");
			        else
			          {
			          	  printf("\nLista:\n");
			          	  Imprime(Inicio);
					  }
					getch();
					break;
					
			case 4: if (Rem_Inicio(&Inicio,&Fim, &val))        
			           printf("\nFoi removido: %d", val);
			        else
			           printf("\nLista Vazia!");
			        getch();
			        break;
			        
			case 5: if (Rem_Fim(&Inicio,&Fim, &val))        
			           printf("\nFoi removido: %d", val);
			        else
			           printf("\nLista Vazia!");
			        getch();
			        break;

			case 6: printf("\nDigite o valor: \n");
					scanf("%d", &val);

					r = Consulta(Inicio,val);

					if (r==NULL)
						printf("\nValor nao existe!\n");
					else
					printf("\nValor = %d\n");
					getch();
					break;	

		    case 7: printf("\nDigite o valor: \n");
		    		scanf("%d", &val);

		    		r = Consulta(Inicio,val);

		    		printf("\nDigite o valor a inserir: \n");
		    		scanf("%d", &val);

		    		if((r == NULL) || (r == Fim))
		    			Ins_Fim(&Inicio, &Fim, val);
		    		else
		    			Ins_Depois(r, val);

		    		printf("\nInsercao com sucesso!\n");
		    		getch();
		    		break;
		    		
		    case 8: printf("\nDigite o valor a remover");
		    		scanf("%d", &val);
		    		
		    		r = Consulta(Inicio,val);

		    		if (r==NULL)
		    			printf("\nValor nao existe!\n");
		    		else
		    		{
		    			if (r==Inicio)
		    				Rem_Inicio(&Inicio, &Fim, &val);
		    			else if (r== Fim)
		    				Rem_Fim(&Inicio, &Fim, &val);
		    			else
		    				Rem_meio(r);

		    			printf("\nRemocao com sucesso\n");
		    		}
		    		getch();
		    		break;

		    case 9:;

			        
		}		
	} while (op!=0);
	
	
}










