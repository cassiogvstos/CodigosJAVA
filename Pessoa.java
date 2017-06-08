public abstract class Pessoa
{
	private String nome,cpf,rg,telefone;
	
	public Pessoa()
	{
		System.out.printf("Construtor de Pessoa - vazio\n");
	}
	
	public Pessoa(String n){ 
		System.out.printf("Construtor de Pessoa\n");
		nome = n; 
	}
	
	public void apresentar()
	{
		System.out.printf("Sou o %s, meu cpf eh %s, meu rg eh %s e meu telefone eh %s.\n",
							nome,cpf,rg,telefone);
	}
	
	public String toString()
	{
		return "Sou um(a) "+getClass().getName()+" Sou o "+nome+", meu cpf eh "+cpf+", meu rg eh "+rg+" e meu telefone eh "+telefone;
	}
	
	public boolean equals(Object obj)
	{
		if(obj==null) return false;

		if(obj instanceof Pessoa)
		{
			return(
				//comparar nome
				((((nome!=null) && (nome.equals(((Pessoa)obj).getNome())))) || (((Pessoa)obj).getNome()==null))	&&
				//comparar cpf
				(((cpf!=null) && (cpf.equals(((Pessoa)obj).getCpf()))) ||      (((Pessoa)obj).getCpf()==null))
				&&
				//comparar rg
				(((rg!=null) && (rg.equals(((Pessoa)obj).getRg()))) ||
				(((Pessoa)obj).getRg()==null))
				&&
				//comparar telefone
				(((telefone!=null) && (telefone.equals(((Pessoa)obj).getTelefone()))) ||
				(((Pessoa)obj).getTelefone()==null))
			   );
			
			/*if (nome==null) {
				if(((Pessoa)obj).getNome()==null)
					return true;
				else
					return false;
			}
			else
			{
				return nome.equals(((Pessoa)obj).getNome());
			}*/
			
		}
		else
			return false;
	}
	

	public void setNome(String v) { nome = v; }
	public void setCpf(String v) { cpf = v; }
	public void setRg(String v) { rg = v; }
	public void setTelefone(String v) { telefone = v; }
	
	public String getNome() { return nome; }
	public String getCpf() { return cpf; }
	public String getRg() { return rg; }
	public String getTelefone() { return telefone; }

	public abstract void executarTarefa();
}
