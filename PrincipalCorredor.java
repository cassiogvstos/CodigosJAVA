import java.util.Scanner;
public class PrincipalCorredor
{
	public static void main(String args[]) 
	{
		Scanner teclado = new Scanner(System.in);

		Corredor c;

		System.out.printf("1 - Triatleta\nOutros - Cachorros");
		int op = teclado.nextInt(); teclado.nextLine();

		if (op == 1) c = new Triatleta();
		else c = new Cachorro();

		c.correr();
	}
}