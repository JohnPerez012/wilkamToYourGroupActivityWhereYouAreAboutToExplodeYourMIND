#include <stdio.h>
#include <string.h>

void createHappyPathFlow();
void createStoryboard();
void identifyInteractionPrinciples();
void submitFinalOutput();

int main() {
    char response[10];

    printf("=== HCI Group 2: Storyboarding & Interaction Flow ===\n");
    printf("Are you ready to proceed with this phase? (yes/ready): ");
    scanf("%9s", response);

    if (strcmp(response, "yes") == 0 || strcmp(response, "ready") == 0) {
        printf("\nGreat! Launching the Storyboarding and Interaction Design Module...\n\n");

        createHappyPathFlow();
        createStoryboard();
        identifyInteractionPrinciples();
        submitFinalOutput();

    } else {
        printf("\n⚠️ Pag pray usa ara\n");
        printf("Run this program again once you're ready.\n");
    }

    return 0;
}

void createHappyPathFlow() {
    printf("=== Task 1: Map a 'Happy Path' User Flow ===\n");
    printf("Objective: Visualize the ideal, successful path the user follows to complete a task.\n\n");

    printf("Example Flow:\n");
    printf("   [Login] -> [Home Screen] -> [Search Food] -> [Select Item]\n");
    printf("   -> [Add to Cart] -> [Checkout] -> [Order Confirmation]\n\n");

    printf("Deliverable: A Flowchart Diagram showing screens, decisions, and transitions.\n");
    printf("Tools you can use: draw.io, Figma, PowerPoint shapes, or hand-drawn flow.\n\n");
}

void createStoryboard() {
    printf("=== Task 2: Create a Storyboard ===\n");
    printf("Objective: Illustrate the user's emotional and contextual journey before, during,\n");
    printf("and after using the product.\n\n");

    printf("Storyboard Frame Guide (6 Frames):\n");
    printf("1–2: Before – show the user's problem or frustration.\n");
    printf("3–5: During – user interacts with the interface or system.\n");
    printf("6: After – success and emotional reaction.\n\n");

    printf("Tip: Use stick figures or simple sketches with captions and emotions.\n");
    printf("Deliverable: A 6-frame storyboard (digital or photo of drawings).\n\n");
}

void identifyInteractionPrinciples() {
    printf("=== Task 3: Identify Key Interaction Principles ===\n");
    printf("Objective: Select and explain three HCI principles that ensure a successful design.\n\n");

    printf("Recommended Principles:\n");
    printf("1. Fitts's Law – Buttons and touch targets should be large enough and easy to reach.\n");
    printf("2. Visibility – Important options and feedback must be clearly seen by the user.\n");
    printf("3. Feedback – Every action should produce an immediate system response.\n\n");

    printf("Deliverable: A list of 3 principles with 1–2 sentence explanations of relevance.\n\n");
}

void submitFinalOutput() {
    printf("=== Final Deliverable ===\n");
    printf("Prepare and submit the following in softcopy format (PDF/Slides):\n");
    printf("1. Happy Path Flowchart (1 page or slide)\n");
    printf("2. 6-Frame Storyboard (1–2 pages)\n");
    printf("3. 3 Key Interaction Principles with brief explanations\n\n");

    printf("Filename: Group2_Storyboarding_HCI.pdf\n");
printf("\n✅ Package everything (HARD COPY, SOFT COPY, DRAFTS, DOCUMENTATION TO SEE YOUR MEMBER CONTRIBUTION or unsa pana diha TANAN!) into Group2_Storyboarding_HCI.pdf"); printf("Submission: Google Classroom / PDF upload.\n"); printf("✅ End of Group 2 Simulation.\n");
}
