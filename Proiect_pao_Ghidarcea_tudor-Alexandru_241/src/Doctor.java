
import java.util.Scanner;

public class Doctor{
    private String Nume;
    private String Prenume;
    Scanner scanner = new Scanner(System.in);
   // private ArrayList<String> Tratamente = new ArrayList<String>();
    public Doctor(String Nume, String Prenume/*,*ArrayList<String> Tratamente*/){

        this.Nume = Nume;
        this.Prenume = Prenume;
        /*this.Tratamente = Tratamente;*/
    }
    public Doctor(){
        this.Nume= "Null";
        this.Prenume="Null";
    }
    public void afisare_Doctor(){
        System.out.print("Numele doctorului este "+Nume+"\n");
        System.out.print("Prenumele doctorului este "+Prenume+"\n");
    }
    


public String getNume(){
     return this.Nume;
}
public String getPrenume(){
    return this.Prenume;
}

/*public ArrayList<String> getTratamente(){
    return this.Tratamente;
}*/


public void setNume(String Nume){
    this.Nume=Nume;
}

public void setPrenume(String Prenume){
    this.Prenume=Prenume;
}

public void citire_Doctor(){
    System.out.print("Introduceti numele doctorului: ");
    Nume=scanner.nextLine();
    System.out.print("Introduceti prenumele doctorului: ");
    Prenume = scanner.nextLine();
}

/*public void setTratamente(ArrayList<String> Tratamente){
    this.Tratamente=Tratamente;
}*/
}