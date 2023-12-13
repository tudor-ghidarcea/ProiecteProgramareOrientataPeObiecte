//tema: programare cabinet medical
//aplicatia va permite pacientilor sa se programeze intr-un cabinet medical, la un anume doctor, la o anumita ora
//aplicatia nu va permite pacientilor sa se programeze in afara orelor de functionare ale cabinetului, sau sa se inscrie la aceeasi ora cu alt pacient
//vom folosi clasa Programare, care va mosteni clasa Doctor, clasa Pacient si va avea atributele sale specifice precum ora 
//programul va ordona programarile dupa ora pentru care corespund, si va afisa programarea aferenta intervalului orar in care este folosit
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
 class App
{
    public static void main(String [] args)
 
    {     Scanner scanner = new Scanner(System.in);
          Connection connection = null;
         // PreparedStatement stmt = null;
         // ResultSet result = null;
         try{
          
          connection =  DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc" , "root", "root");
          
        } catch(Exception e){
            e.printStackTrace();
        }
        int alegere;
        Doctor doctor = new Doctor();
        List<Doctor> listaDoctori =new ArrayList<>();
        Pacient pacient = new Pacient();
        List<Pacient> listaPacienti =new ArrayList<>();
        Programare programare = new Programare();
        List<Programare> listaProgramari =new ArrayList<>();

      
        while(true) {

            
            System.out.println("Proiect PAO Ghidarcea Tudor-Alexandru");
            System.out.println("Aplicatie gestiune cabinet medical");
            System.out.println("Optiunea 1 : Adaugati un medic");
            System.out.println("Optiunea 2 : Stergeti un medic");
            System.out.println("Optiunea 3 : Afisati toti medicii");
            System.out.println("Optiunea 4 : Adaugati un pacient");
            System.out.println("Optiunea 5 : Stergeti un pacient");
            System.out.println("Optiunea 6 : Afisati toti pacientii");
            System.out.println("Optiunea 7 : Creati o rezervare!");
            System.out.println("Optiunea 8: Afisati pe scurt rezervarile ");
            System.out.println("optiunea 9: Afisati in detaliu o rezervare: ");
            System.out.println("Optiunea 10 : Anulati o rezervare ");
            System.out.println("Optiunea 11: Iesire ");

            
            System.out.println("Alegerea dumneavoastra:");
            alegere = scanner.nextInt();

            
            switch (alegere) {

                
                case 1:
                doctor = new Doctor();
                doctor.citire_Doctor();
                listaDoctori.add(doctor);
               try{PreparedStatement stmt = connection.prepareStatement("INSERT INTO medici ( Nume, Prenume) VALUES ( ?, ?)");
                        stmt.setString(1, doctor.getNume());
                        stmt.setString(2, doctor.getPrenume());
            
                        stmt.executeUpdate();}
                        catch(SQLException e){
                            e.printStackTrace();
                        }

                    break;

                
                case 2:
                System.out.println("Al catelea medic ati dori sa stergeti? ");
                    int numar = scanner.nextInt();
                    try{PreparedStatement stmt = connection.prepareStatement("delete from medici where idmedici=?");
                        stmt.setInt(1, numar);
            
                        stmt.executeUpdate();}
                        catch(SQLException e){
                            e.printStackTrace();
                        }
                    break;

                
                case 3:
                try{PreparedStatement stmt = connection.prepareStatement("select * from medici");
    
                ResultSet result=stmt.executeQuery();
                while(result.next()){
                    System.out.println("id Medic= " + result.getInt("idmedici"));
                    System.out.println("Nume = " + result.getString("Nume"));
                    System.out.println("Prenume = "+ result.getString("Prenume"));
                }}
                catch(SQLException e){
                    e.printStackTrace();
                }
                    break;

                
                case 4:
                pacient = new Pacient();
                pacient.citire_Pacient();
                listaPacienti.add(pacient);
               try{PreparedStatement stmt = connection.prepareStatement("INSERT INTO Pacienti ( Nume, Prenume, Diagnostic, Varsta) VALUES ( ?, ?, ?, ?)");
                        stmt.setString(1, pacient.getNume());
                        stmt.setString(2, pacient.getPrenume());
                        stmt.setString(3, pacient.getDiagnostic());
                        stmt.setInt(4, pacient.getVarsta());
            
                        stmt.executeUpdate();}
                        catch(SQLException e){
                            e.printStackTrace();
                        }


                    break;

                case 5:

                System.out.println("Al catelea pacient ati dori sa stergeti? ");
                int nr = scanner.nextInt();
                try{PreparedStatement stmt = connection.prepareStatement("delete from medici where idpacienti=?");
                    stmt.setInt(1, nr);
        
                    stmt.executeUpdate();}
                    catch(SQLException e){
                        e.printStackTrace();
                    }
                break;

                case 6:

                try{PreparedStatement stmt = connection.prepareStatement("select * from pacienti");
    
                ResultSet result=stmt.executeQuery();
                while(result.next()){
                    System.out.println("id pacient= " + result.getInt("idpacienti"));
                    System.out.println("Nume = " + result.getString("Nume"));
                    System.out.println("Prenume = "+ result.getString("Prenume"));
                    System.out.println("Diagnostic: "+result.getString("Diagnostic"));
                    System.out.println("Varsta: "+result.getInt("Varsta"));
                }}
                catch(SQLException e){
                    e.printStackTrace();
                }

                break;

                case 7:
                programare = new Programare();
                programare.citire_Programare();
                listaProgramari.add(programare);
                try{PreparedStatement stmt = connection.prepareStatement("INSERT INTO rezervari ( Pacient, Medic, Ora) VALUES ( ?, ?, ?)");
                stmt.setInt(1, programare.getPacient());
                stmt.setInt(2, programare.getDoctor());
                stmt.setDouble(3, programare.getOra());
    
                stmt.executeUpdate();}
                catch(SQLException e){
                    e.printStackTrace();
                }

            break;
                case 8:
                try{PreparedStatement stmt = connection.prepareStatement("select * from rezervari");
    
                ResultSet result=stmt.executeQuery();
                while(result.next()){
                    System.out.println("id Pacient= " + result.getInt("Pacient"));
                    System.out.println("id Medic = " + result.getInt("Doctor"));
                    System.out.println("Ora programarii = "+ result.getDouble("Ora"));
                }}
                catch(SQLException e){
                    e.printStackTrace();
                }
                    break;

                case 9:
                System.out.println("Nu am implementat corect aceasta functie, mai sus este incercarea mea insa nu am finalizat-o. Intentia mea era iu din baza de date datele despre pacient si medic, in functie de id-ul lor care este stocat in obiectul programare");
                System.out.println("Ce rezervare ati dori sa afisati in detaliu?");
                int numer = scanner.nextInt();
                try{PreparedStatement stmt = connection.prepareStatement("select * from rezervari where idrezervari=?");
                stmt.setInt(1,numer);
                ResultSet result=stmt.executeQuery();
                while(result.next()){
                    
                    stmt = connection.prepareStatement("select * from medici where idmedici=?");
                    stmt.setInt(1, result.getInt("Doctor"));
                    result.close();
                    result=stmt.executeQuery();
                  
                    System.out.println("Numele Medicului = " + result.getString("Nume"));
                    System.out.println("Prenumele Medicului = "+ result.getString("Prenume"));
                }}
                catch(SQLException e){
                    e.printStackTrace();
                }
                
                    break;
                case 10:
                System.out.println("A cata rezervare ati dori sa stergeti? ");
                int num = scanner.nextInt();
                try{PreparedStatement stmt = connection.prepareStatement("delete from rezervari where idrezervari=?");
                    stmt.setInt(1, num);
        
                    stmt.executeUpdate();}
                    catch(SQLException e){
                        e.printStackTrace();
                    }
                break;

                case 11:
                    System.exit(0);

                
                default:
                    System.out.println("Va rugam introduceti o optiune valida! \\n\\n");
            }//scanner.close();
        }
    }
    }
