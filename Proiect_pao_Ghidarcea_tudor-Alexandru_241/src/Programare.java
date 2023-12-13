import java.util.Scanner;

public class Programare{
    private Integer Pacient;
    private Integer Doctor;
    private Double Ora;
    Scanner scanner = new Scanner(System.in);
    public Programare(int Pacient, int Doctor, Double ora){

        this.Pacient= Pacient;
        this.Doctor = Doctor;
        this.Ora = Ora;
       // this.NumePacient = Pacient::Pacient1.getNume();
    }
    public Programare(){
        this.Pacient = 0;
        this.Doctor=0;
        this.Ora=0.0;
    }
    public void citire_Programare(){
        System.out.print("Introduceti numarul corespunzator pacientului: ");
        Pacient=scanner.nextInt();
        System.out.print("Introduceti numele corespunzator doctorului: ");
        Doctor = scanner.nextInt();
        System.out.print("Introduceti ora dorita: ");
        Ora = scanner.nextDouble();

    }
    public void afisare_Programare(){
        System.out.print("Numarul pacientului este "+Pacient+"\n");
        System.out.print("Numarul doctorului este "+Doctor+"\n");
        System.out.print("Ora programarii este: "+Ora+"\n");
    }
    



public int getPacient(){
     return this.Pacient;
}
public int getDoctor(){
    return this.Doctor;
}

public Double getOra(){
    return this.Ora;
}


public void setPacient(int Pacient){
    this.Pacient=Pacient;
}

public void setDoctor(int Doctor){
    this.Doctor=Doctor;
}

public void setOra(Double Ora){
    this.Ora=Ora;
}

public void setVarsta(int Varsta){
    if (Ora<=18&&Ora>=6)
{
   this.Ora = Ora;
}
    else{System.out.println("Programul cabinetului este intre orele 6 si 19!");}
}
}