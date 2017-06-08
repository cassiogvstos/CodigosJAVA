public class Triatleta extends Pessoa implements Corredor, Nadador, Ciclista
{
	public void executarTarefa()
	{
		correr(); andar(); pedalar();
	}

	public void correr()
	{
		System.out.printf("Triatleta correndo\n");
	}
	public void nadar()
	{
		System.out.printf("Triatleta nadando\n");
	}
	public void pedalar();
	{
		System.out.printf("Triatleta pedadlando\n");
	}
}