
import java.util.Scanner;

public class Pacient{
    private String Nume;
    private String Prenume;
    private String Diagnostic;
    private int Varsta;
    Scanner scanner = new Scanner(System.in);
    public Pacient(String Nume, String Prenume, String Diagnostic, Integer Varsta){

        this.Nume = Nume;
        this.Prenume = Prenume;
        this.Diagnostic = Diagnostic;
        this.Varsta = Varsta;
    }
    public Pacient(){
        this.Nume="Null";
        this.Prenume="Null";
        this.Diagnostic="Null";
        this.Varsta=0;
    }


public String getNume(){
     return this.Nume;
}
public String getPrenume(){
    return this.Prenume;
}

public String getDiagnostic(){
    return this.Diagnostic;
}

public int getVarsta(){
    return this.Varsta;
}

public void setNume(String Nume){
    this.Nume=Nume;
}

public void setPrenume(String Prenume){
    this.Prenume=Prenume;
}

public void setDiagnostic(String Diagnostic){
    this.Diagnostic=Diagnostic;
}

public void setVarsta(int Varsta){
    if (Varsta== (int)Varsta)
{
   this.Varsta = Varsta;
}
    else{System.out.println("Introduceti o varsta valida");}

}
public void citire_Pacient(){
    System.out.print("Introduceti numele pacientului: ");
    Nume=scanner.nextLine();
    System.out.print("Introduceti prenumele pacientului: ");
    Prenume = scanner.nextLine();
    System.out.print("Introduceti diagnosticul pacientului:");
    Diagnostic = scanner.nextLine();
    System.out.print("Introduceti varsta pacientului: ");
    Varsta = scanner.nextInt();
}

public void afisare_Pacient(){
    System.out.print("Numele pacientului este "+Nume);
    System.out.print("Prenumele pacientului este "+Prenume);
    System.out.print("Diagnosticul pacientului este "+Diagnostic);
    System.out.print("Varsta pacientului este "+Varsta);
}

}