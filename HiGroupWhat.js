// group4_ia.js
// Simulation for Group 4: Conceptual Structure & Information Architecture

const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const lower = (s) => String(s || '').toLowerCase();

function generateFeatures(topic) {
    const t = lower(topic);
    if (t.includes("game")) {
        return [
            "Audio Settings", "Graphics Quality", "Controls", "Notifications",
            "Save/Load", "Leaderboards", "Account", "Privacy",
            "In-App Purchases", "Language"
        ];
    }
    if (t.includes("shop") || t.includes("store")) {
        return [
            "Search", "Categories", "Cart", "Wishlist", "Order History",
            "Payment Methods", "Shipping Address", "Returns", "Account", "Notifications"
        ];
    }
    return [
        "Dashboard", "Search", "Profile", "Notifications", "Settings",
        "Help", "Reports", "Privacy", "Messages", "Feedback"
    ];
}

function groupFeatures(features) {
    const groups = [
        { name: "Account & Personalization", items: [] },
        { name: "Core Tasks", items: [] },
        { name: "Support & System", items: [] }
    ];

    features.forEach(f => {
        const k = lower(f);
        if (k.match(/account|profile|privacy|payment|shipping|wishlist/)) groups[0].items.push(f);
        else if (k.match(/dashboard|search|categories|reports|orders|leader/)) groups[1].items.push(f);
        else groups[2].items.push(f);
    });

    // Optional 4th group for notifications/messages
    const notif = groups[2].items.filter(f => lower(f).includes("notification") || lower(f).includes("message"));
    if (notif.length >= 2) {
        groups.push({ name: "Notifications & Messaging", items: notif });
        groups[2].items = groups[2].items.filter(f => !notif.includes(f));
    }

    return groups;
}

function generateAffinity() {
    const raw = [
        "App is slow to load", "Search results irrelevant",
        "Hard to find refund option", "Too many ads",
        "Payment failed for no reason", "Profile settings hard to locate",
        "Missing dark mode", "Buttons too small",
        "Overwhelming notifications", "No progress indicators",
        "Confusing button labels", "Cannot save drafts",
        "Help section unclear", "Inconsistent icons",
        "No keyboard shortcuts"
    ];

    const clusters = {
        "Performance & Stability": [],
        "Navigation & Discoverability": [],
        "UI & Accessibility": [],
        "Transactions & Feedback": []
    };

    raw.forEach(r => {
        const k = lower(r);

        if (k.match(/slow|load|fail/)) clusters["Performance & Stability"].push(r);
        else if (k.match(/find|search|locate|labels|help/)) clusters["Navigation & Discoverability"].push(r);
        else if (k.match(/small|dark|icon|keyboard|read/)) clusters["UI & Accessibility"].push(r);
        else clusters["Transactions & Feedback"].push(r);
    });

    return clusters;
}

function generateWireflow(goal) {
    const g = lower(goal);
    if (g.includes("refund")) {
        return [
            { screen: "Orders List", action: "User selects an order" },
            { screen: "Order Details", action: "Tap 'Request Refund' → fill reason" },
            { screen: "Refund Confirmation", action: "System shows status & ETA" }
        ];
    }
    return [
        { screen: "Dashboard", action: "User identifies goal" },
        { screen: "Task Screen", action: "User completes main action" },
        { screen: "Confirmation", action: "System confirms completion" }
    ];
}

function printCardSort(topic, features, groups) {
    console.log("\n========== OPEN CARD SORT ==========\n");
    console.log("Topic:", topic, "\n");

    console.log("10 Features:");
    features.forEach((f, i) => console.log(` ${i + 1}. ${f}`));

    console.log("\nHierarchy Diagram (3–4 groups):");
    groups.forEach(g => {
        console.log(`\n[ ${g.name} ]`);
        g.items.forEach(i => console.log("  •", i));
    });

    console.log("\n--------------------------------------\n");
}

function printAffinity(clusters) {
    console.log("========== AFFINITY DIAGRAM ==========\n");

    Object.keys(clusters).forEach(cluster => {
        console.log(`[ ${cluster} ]`);
        clusters[cluster].forEach(i => console.log(" -", i));

        let logic = "";
        if (cluster.includes("Performance")) logic = "Items relate to speed, failures, and system responsiveness.";
        else if (cluster.includes("Navigation")) logic = "Items show difficulty locating or understanding features.";
        else if (cluster.includes("UI")) logic = "Items relate to readability, control size, and accessibility issues.";
        else logic = "Items relate to errors, transactions, ads, notifications, and feedback.";

        console.log(" Logic:", logic, "\n");
    });

    console.log("--------------------------------------\n");
}

function printWireflow(goal, wireflow) {
    console.log("========== CONCEPTUAL WIREFLOW ==========\n");
    console.log("User Goal:", goal, "\n");

    wireflow.forEach((step, i) => {
        console.log(`Screen ${i + 1}: ${step.screen}`);
        console.log(` Action: ${step.action}\n`);
    });

    console.log("Flow:");
    console.log(` ${wireflow[0].screen} → ${wireflow[1].screen}`);
    console.log(` ${wireflow[1].screen} → ${wireflow[2].screen}`);
    console.log("\n--------------------------------------\n");
}

// === MAIN FLOW ===
rl.question("Are you ready to generate Group 4 outputs? (yes/no): ", answer => {
    if (lower(answer) !== "yes") {
        console.log("\nRun again when you're ready.");
        rl.close();
        return;
    }

    rl.question("\nEnter your topic (e.g., Mobile Game, Online Store, Portal): ", topic => {
        const features = generateFeatures(topic);
        const groups = groupFeatures(features);

        rl.question("\nEnter a user goal for the 3-screen wireflow (e.g., Requesting a refund): ", goal => {
            const flow = generateWireflow(goal);

            console.log("\n===== GENERATING GROUP 4 ARTIFACTS =====\n");

            printCardSort(topic, features, groups);
            printAffinity(generateAffinity());
            printWireflow(goal, flow);

            console.log("🎉 All conceptual deliverables generated!");
            console.log("Suggested filename: Group4_ConceptualIA_HCI.pdf\n");

            rl.close();
        });
    });
});
