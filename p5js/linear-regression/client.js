const data = new Array();
let m = 1;
let b = 0;

function setup() {
  createCanvas(400, 400);
}

const drawLine = () => {
  let x1 = 0;
  let y1 = m * x1 + b;
  let x2 = 1;
  let y2 = m * x2 + b;

  x1 = map(x1, 0, 1, 0, width);
  y1 = map(y1, 0, 1, height, 0);
  x2 = map(x2, 0, 1, 0, width);
  y2 = map(y2, 0, 1, height, 0);
  stroke(255);
  line(x1, y1, x2, y2);
};

const linearRegression = () => {
  let xSum = 0,
    ySum = 0;

  data.forEach((cv) => {
    xSum += cv.x;
    ySum += cv.y;
  });

  const xMean = xSum / data.length;
  const yMean = ySum / data.length;

  let num = 0;
  let dem = 0;
  data.forEach((cv) => {
    num += (cv.x - xMean) * (cv.y - yMean);
    dem += (cv.x - xMean) * (cv.x - xMean);
  });

  m = num / dem;
  b = yMean - m * xMean;
};

function draw() {
  background(50);
  strokeWeight(12);
  data.forEach((cv) => {
    stroke(255);
    point(map(cv.x, 0, 1, 0, width), map(cv.y, 0, 1, height, 0));
  });

  if (data.length > 1) {
    print(m, b);
    linearRegression();
    strokeWeight(5);
    drawLine();
  }
}

function mousePressed() {
  const x = map(mouseX, 0, width, 0, 1);
  const y = map(mouseY, 0, height, 1, 0);

  const point = createVector(x, y);
  data.push(point);
}
