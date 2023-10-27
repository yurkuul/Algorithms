let circles = []

document.addEventListener("click", function (e) {
    console.log("hi", e.clientX, e.clientY);

    let circle = {
        x: e.clientX,
        y: e.clientY,
        r: 5
    }

    // Set CSS properties for the created <div> element
    circle["e"] = document.createElement('button');
    circle["e"].style.width = (2 * circle.r) + 'px';
    circle["e"].style.height = (2 * circle.r) + 'px';
    circle["e"].style.borderRadius = '50%';

    const randomColor = getRandomColor();
    circle["e"].style.backgroundColor = randomColor;

    circle["e"].style.position = 'absolute'; // Set the position to absolute
    circle["e"].style.left = circle.x + 'px'; // Set the left position
    circle["e"].style.top = circle.y + 'px';  // Set the top position

    circle["e"].addEventListener("click", function (e) {
        //Increase the radius of the circle
        circle.r += 5; // Increase the radius by 5 pixels

        // Update the circle's width and height
        circle["e"].style.width = (2 * circle.r) + 'px';
        circle["e"].style.height = (2 * circle.r) + 'px';
    })

    // Append the <div> element to the DOM or a specific container
    document.body.appendChild(circle["e"]);

    circles.push(circle)
})

setInterval(() => {
    console.log("I am Lisa");

    //Move colliding circles apart
    for (let i = 0; i < circles.length; i++) {
        for (let j = i + 1; j < circles.length; j++) {
            const circle1 = circles[i];
            const circle2 = circles[j];

            // Calculate the distance between the centers of the two circles
            const distance = Math.sqrt(
                Math.pow(circle1.x - circle2.x, 2) + Math.pow(circle1.y - circle2.y, 2)
            );

            // Check if the circles are colliding (overlapping)
            if (distance < circle1.r + circle2.r) {
                // Calculate the angle between the two circle centers
                const angle = Math.atan2(circle2.y - circle1.y, circle2.x - circle1.x);

                // Calculate the new positions to move the circles apart
                const newDistance = circle1.r + circle2.r;
                const newX1 = circle1.x + Math.cos(angle) * newDistance / 2;
                const newY1 = circle1.y + Math.sin(angle) * newDistance / 2;
                const newX2 = circle2.x - Math.cos(angle) * newDistance / 2;
                const newY2 = circle2.y - Math.sin(angle) * newDistance / 2;

                // Update the circle positions
                circle1.x = newX1;
                circle1.y = newY1;
                circle2.x = newX2;
                circle2.y = newY2;

                //Update the css
                // Update the CSS properties for the first circle
                circle1.e.style.left = circle1.x + 'px';
                circle1.e.style.top = circle1.y + 'px';

                // Update the CSS properties for the second circle
                circle2.e.style.left = circle2.x + 'px';
                circle2.e.style.top = circle2.y + 'px';
            }
        }
    }

}, 1000)

function getRandomColor() {
    // Generate random values for red, green, and blue components
    const red = Math.floor(Math.random() * 256);
    const green = Math.floor(Math.random() * 256);
    const blue = Math.floor(Math.random() * 256);

    // Convert the RGB values to a hexadecimal color code
    const color = "#" + (1 << 24 | red << 16 | green << 8 | blue).toString(16).slice(1).toUpperCase();

    return color;
}