import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("=== HCI Group 1: The User & Problem Definition ===");
        System.out.print("Are you ready to proceed with the project? (yes/ready): ");
        String userResponse = input.nextLine().trim().toLowerCase();

        if (userResponse.equals("yes") || userResponse.equals("ready")) {
            System.out.println("\nGreat! Initializing HCI Discovery Process...\n");
            createUserPersona();
            defineProblemStatement();
            conductCompetitorAnalysis();
            submitFinalOutput();
        } else {
            System.out.println("\n⚠️ AY PAG READY DIHA UY KAKAPOY BAYA NIMO!");
            System.out.println("Run the program again once you’re ready.");
        }

        input.close();
    }

    static void createUserPersona() {
        System.out.println("=== Task 1: Create a User Persona ===");
        // NOTE: ATLEAST 3!
        int sampleSize = 3 + (int)(Math.random() * ((5 - 3) + 1)); // 3 to 5
        System.out.println("Interviewing " + sampleSize + " target users...");

        while (gatheringData()) {
            observeDailyRoutine();
            askFrustrationsAndGoals();
            noteToolsAndBehaviors();
        }

        Persona miaCruz = new Persona(
            "Juan Cruz", 99, "College Student",
            "Order food quickly between classes",
            "App takes too long to load and crashes during checkout",
            "\"If it’s not fast, I’d rather skip lunch.\""
        );

        miaCruz.displayProfile();
    }

    static void defineProblemStatement() {
        System.out.println("=== Task 2: Define the Problem Statement ===");
        String persona = "Mia Cruz";
        String frustration = "cannot order food efficiently";
        String rootCause = "the app requires too many steps before checkout";
        String problemStatement =
            "Our user " + persona + " has a problem where " +
            frustration + " because " + rootCause + ".";
        System.out.println(problemStatement + "\n");
    }

    static void conductCompetitorAnalysis() {
        System.out.println("=== Task 3: Conduct a Competitor Analysis ===");
        String[][] competitors = {
            {"GrabFood", "Clear menus, fast order", "Too many ads"},
            {"FoodPanda", "Good order tracking", "Cluttered interface"}
        };
        for (String[] c : competitors) {
            System.out.println("Analyzing: " + c[0]);
            System.out.println("Strengths: " + c[1]);
            System.out.println("Weaknesses: " + c[2]);
            System.out.println();
        }

        System.out.println("Design Lessons:");
        System.out.println("- Simplify layout to improve perception");
        System.out.println("- Provide real-time feedback for user confidence\n");
    }

    static void submitFinalOutput() {
        System.out.println("=== Final Deliverable ===");
        String[] deliverables = {
            "1. User Persona Profile (1 page/slide)",
            "2. Problem Statement (1-3 sentences + context)",
            "3. Competitor Analysis Table",
            "4. Optional: Reflection or references"
        };
        for (String item : deliverables) System.out.println(item);
System.out.println("\n✅ Package everything (HARD COPY, SOFT COPY, DRAFTS, DOCUMENTATION TO SEE IF YOUR MEMBER CONTRIBUTION or unsa pana diha TANAN!) into Group1_UserAndProblemDefinition_HCI.pdf");        
System.out.println("Submission: Google Classroom / PDF upload.\n");
    }

    // Mock helpers (simulate process)
    static boolean userIsReady() { return true; }
    static boolean gatheringData() { return false; }
    static void observeDailyRoutine() {}
    static void askFrustrationsAndGoals() {}
    static void noteToolsAndBehaviors() {}

    // Persona class
    static class Persona {
        String name; int age; String occupation, goal, frustration, quote;
        Persona(String n,int a,String o,String g,String f,String q){
            name=n; age=a; occupation=o; goal=g; frustration=f; quote=q;
        }
        void displayProfile() {
            System.out.println("\nPersona: " + name +
                "\nAge: " + age +
                "\nOccupation: " + occupation +
                "\nGoal: " + goal +
                "\nFrustration: " + frustration +
                "\nQuote: " + quote + "\n");
        }
    }
}
