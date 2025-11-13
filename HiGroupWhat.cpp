#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void generateScenarios(const string &product) {
    cout << "=== Task 1: Develop Usability Scenarios ===\n\n";
    cout << "Target interface: " << product << "\n\n";

    // Basic heuristics to guess product type from name
    string p = toLower(product);

    vector<string> scenarios;
    if (p.find("shop") != string::npos || p.find("store") != string::npos ||
        p.find("cart") != string::npos || p.find("e-comm") != string::npos ||
        p.find("market") != string::npos) {
        scenarios = {
            "1) Search for a wireless mouse under \u20B1500 and add it to your cart, then go to checkout.",
            "2) Apply a discount code at checkout and complete the purchase using a saved card.",
            "3) Track an existing order from the home screen to view estimated delivery time."
        };
    } else if (p.find("flight") != string::npos || p.find("travel") != string::npos ||
               p.find("air") != string::npos || p.find("ticket") != string::npos) {
        scenarios = {
            "1) Find a flight to London departing next Tuesday and add it to your cart.",
            "2) Select economy class, choose a seat, and proceed to payment.",
            "3) View and modify an existing booking (change passenger name or add baggage)."
        };
    } else if (p.find("video") != string::npos || p.find("netflix") != string::npos ||
               p.find("movie") != string::npos || p.find("stream") != string::npos) {
        scenarios = {
            "1) Find a comedy released in 2022 and add it to your watchlist.",
            "2) Start playback, enable subtitles, then change playback quality.",
            "3) Rate a watched movie and find related recommendations."
        };
    } else {
        // Generic scenarios
        scenarios = {
            "1) Log in to your account, find a core feature, and complete a related task (e.g., add an item, submit a form).",
            "2) Update your profile or account settings (change email or password) and save the changes.",
            "3) Use the search or navigation to locate a specific content item and view its details."
        };
    }

    cout << "Three test scenarios (specific, measurable):\n";
    for (auto &s : scenarios) cout << s << "\n";
    cout << "\n(Each scenario should be completable in <= 5 minutes during usability testing.)\n\n";
}

void heuristicEvaluation(const string &product) {
    cout << "=== Task 2: Conduct a Heuristic Evaluation ===\n\n";
    cout << "Applying Nielsen's 10 heuristics to: " << product << "\n\n";

    // We'll produce two plausible critical violations with suggested fixes.
    // We pick likely issues depending on product hints
    string p = toLower(product);

    struct Violation { string heuristic; string location; string severity; string suggestion; };

    vector<Violation> violations;

    // Heuristic choices (examples)
    if (p.find("shop") != string::npos || p.find("store") != string::npos) {
        violations.push_back({
            "Visibility of system status",
            "Checkout page — no progress indicator during payment processing",
            "Critical",
            "Add a visible progress indicator or confirmation that payment is processing to prevent duplicate submissions."
        });
        violations.push_back({
            "Error prevention / Match between system and the real world",
            "Product listing — ambiguous 'Add' vs 'Buy Now' buttons causing accidental purchases",
            "Major",
            "Use consistent, explicit button labels (e.g., 'Add to Cart' vs 'Buy Now') and confirm destructive actions."
        });
    } else if (p.find("flight") != string::npos || p.find("travel") != string::npos) {
        violations.push_back({
            "Help users recognize, diagnose, and recover from errors",
            "Booking form — unclear error messages when passenger info is invalid",
            "Critical",
            "Provide inline validation with descriptive messages and highlight the field requiring correction."
        });
        violations.push_back({
            "Consistency and standards",
            "Seat selection UI — controls differ across pages",
            "Major",
            "Standardize seat selection interactions and labels across the booking flow."
        });
    } else if (p.find("video") != string::npos || p.find("stream") != string::npos) {
        violations.push_back({
            "Visibility of system status",
            "Player — no buffering indicator and playback controls disappear unexpectedly",
            "Critical",
            "Always show a buffering indicator and persistent, accessible playback controls on hover/tap."
        });
        violations.push_back({
            "Recognition rather than recall",
            "Discovery page — hidden filters force users to remember categories",
            "Major",
            "Expose common filters and remember user filter selections between sessions."
        });
    } else {
        // Generic plausible issues
        violations.push_back({
            "Visibility of system status",
            "Form submission / long-running actions — no feedback when action is processing",
            "Critical",
            "Add progress indicators and disable repeated submit actions until complete."
        });
        violations.push_back({
            "Error prevention",
            "Multi-step process — allows proceeding with incomplete required fields",
            "Major",
            "Validate required fields before allowing the user to continue; warn and guide corrections."
        });
    }

    cout << "Heuristic Violation Report (two critical/major issues):\n\n";
    cout << "No | Heuristic Violated | Location | Severity | Suggested Fix\n";
    cout << "---|--------------------|----------|----------|---------------\n";
    for (size_t i = 0; i < violations.size(); ++i) {
        cout << (i+1) << "  | " << violations[i].heuristic
             << " | " << violations[i].location
             << " | " << violations[i].severity
             << " | " << violations[i].suggestion << "\n";
    }
    cout << "\n(Severity legend: Critical = prevents task completion or causes data loss; Major = strong usability impediment.)\n\n";
}

void proposeKPIs(const string &product) {
    cout << "=== Task 3: Propose Key Performance Indicators (KPIs) ===\n\n";
    cout << "Selecting two measurable KPIs appropriate for evaluating " << product << " after launch.\n\n";

    // Provide general recommended KPIs and reasons
    cout << "KPI 1: Task Success Rate\n";
    cout << " - Definition: Percentage of test users who complete the target core task without assistance.\n";
    cout << " - Why it matters: Direct measure of effectiveness; target threshold often >= 85–90% for core tasks.\n\n";

    cout << "KPI 2: Time on Task (Average)\n";
    cout << " - Definition: Average time (in seconds) that users take to complete the core task.\n";
    cout << " - Why it matters: Shows efficiency and friction; compare to benchmark times to detect regressions.\n\n";

    // Optional supplementary KPIs
    cout << "Optional additional KPIs (if relevant): Error Rate, System Usability Scale (SUS), Post-task Satisfaction (1-5), Retention/Return Rate.\n\n";
}

void submitChecklist() {
    cout << "=== Final Output & Submission Checklist ===\n\n";
    cout << "Prepare and submit the following softcopy materials (PDF/Slides):\n";
    cout << "1) Three Usability Test Scenarios (clear goal, start condition, expected outcome).\n";
    cout << "2) Heuristic Violation Report (2 critical/major issues with suggested fixes).\n";
    cout << "3) Two KPIs with definitions and target benchmarks.\n\n";
    cout << "Suggested filename: Group3_UsabilityAndTesting_Independent.pdf\n";

 cout << "\n✅ Package everything (HARD COPY, SOFT COPY, DRAFTS, DOCUMENTATION TO SEE IF YOUR MEMBER CONTRIBUTION or unsa pana diha TANAN!) into Suggested filename";       
    cout << "Submission method: Google Classrooml\n";
}

int main() {
    string ready;
    cout << "=== Group 3: Usability & Testing (Independent) — Simulation ===\n";
    cout << "Are you ready to run the evaluation simulation? (yes/ready): ";
    getline(cin, ready);
    ready = toLower(ready);

    if (!(ready == "yes" || ready == "ready")) {
        cout << "\nPlease prepare your test target and run again when ready.\n";
        return 0;
    }

    string product;
    cout << "\nEnter the name or type of interface you will evaluate (e.g.,'Acme Shop', 'Campus Portal', 'AirFly') OR BISAN UNSA: ";
    getline(cin, product);
    if (product.empty()) product = "Sample Interface";

    cout << "\n--- Starting independent evaluation for: " << product << " ---\n\n";

    generateScenarios(product);
    heuristicEvaluation(product);
    proposeKPIs(product);
    submitChecklist();

    cout << "=== End of Simulation ===\n";
    return 0;
}
