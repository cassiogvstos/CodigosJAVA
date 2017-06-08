public class Cachorro implements Corredor
{
	private String raca;

	public void setRaca(String r){
		raca = r;
	}
	public String getRaca(){
		return raca;
	}

	public void correr(){
		System.out.printf("Cachorro correndo\n");
	}
}