document.addEventListener("DOMContentLoaded", function() {
    function loadStatus() {
        fetch('/api/status')
        .then(response => response.json())
        .then(data => {
        let statusDiv = document.getElementById('status');

        statusDiv.innerHTML = `
            <p>Power Source: <strong>${data.powerSource === "mains" ? "Mains ⚡" : "Battery 🔋"}</strong></p>
            <p>Battery Level: ${data.batteryLevel}%</p>
            <p>Router is ${data.routerState.toUpperCase()}</p>
            <p>Current Hour: ${data.currentHour}</p>
        `;
        });
    }

    document.getElementById('togglePower').addEventListener('click', function() {
        fetch('/api/togglePower', { method: 'POST' })
        .then(() => loadStatus());
    });

    document.getElementById('setTimeBtn').addEventListener('click', function() {
        let hour = document.getElementById('hourInput').value;
        fetch('/api/setTime', {
            method: 'POST',
            headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
            body: `hour=${encodeURIComponent(hour)}`
        })
        .then(() => loadStatus());
    });

    document.getElementById('setSettingsBtn').addEventListener('click', function() {
        let startHour = document.getElementById('startHourInput').value;
        let endHour = document.getElementById('endHourInput').value;
        fetch('/api/setSettings', {
            method: 'POST',
            headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
            body: `startHour=${encodeURIComponent(startHour)}&endHour=${encodeURIComponent(endHour)}`
        })
        .then(() => loadStatus());
    });

    // Инициализируем статус при загрузке
    loadStatus();
    });
