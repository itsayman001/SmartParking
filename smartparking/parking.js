// Parking system logic (mirrors your C++ code)
const totalSpots = 10;
const spots = Array(totalSpots).fill(null);

function parkVehicle() {
    const plate = document.getElementById("plateInput").value.trim();
    if (!plate) return alert("Enter a license plate!");

    for (let i = 0; i < totalSpots; i++) {
        if (!spots[i]) {
            spots[i] = { plate, entryTime: new Date() };
            alert(`Vehicle ${plate} parked in spot ${i + 1}`);
            displayStatus();
            return;
        }
    }
    alert("No available spots!");
}

function removeVehicle() {
    const plate = document.getElementById("plateInput").value.trim();
    if (!plate) return alert("Enter a license plate!");

    for (let i = 0; i < totalSpots; i++) {
        if (spots[i] && spots[i].plate === plate) {
            const exitTime = new Date();
            const hours = (exitTime - spots[i].entryTime) / 3600000; // ms → hours
            const fee = (hours * 5).toFixed(2);
            alert(`Vehicle ${plate} removed from spot ${i + 1}. Fee: $${fee}`);
            spots[i] = null;
            displayStatus();
            return;
        }
    }
    alert("Vehicle not found!");
}

function displayStatus() {
    let statusHTML = "<h3>Parking Status:</h3><ul>";
    for (let i = 0; i < totalSpots; i++) {
        statusHTML += `<li>Spot ${i + 1}: ${spots[i] ? spots[i].plate : "Empty"}</li>`;
    }
    statusHTML += "</ul>";
    document.getElementById("status").innerHTML = statusHTML;
}
