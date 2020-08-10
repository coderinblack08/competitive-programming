let cities,
  recordDistance = Infinity;
const totalCities = 3;

function setup() {
  createCanvas(400, 400);
  cities = Array.from(new Array(totalCities), (city) =>
    createVector(random(width), random(height))
  );
}

const swap = (arr, i, j) => {
  [arr[i], arr[j]] = [arr[j], arr[i]];
};

const shuffleArray = (arr) => {
  const i = floor(random(totalCities)),
    j = floor(random(totalCities));
  swap(arr, i, j);
};

const calcDistance = (arr) => {
  let sum = 0;
  for (let i = 0; i < arr.length - 1; i++) {
    const d = dist(arr[i].x, arr[i].y, arr[i + 1].x, arr[i + 1].y);
    sum += d;
  }
  return sum;
};

function draw() {
  background(0);

  fill(255);
  noStroke();
  cities.forEach((city) => {
    ellipse(city.x, city.y, 10, 10);
  });

  stroke(255);
  strokeWeight(3);
  noFill();
  beginShape();
  cities.forEach((city) => {
    vertex(city.x, city.y);
  });
  endShape();

  shuffleArray(cities);

  const previousRecord = recordDistance;
  const currentDistance = calcDistance(cities);
  recordDistance = Math.min(recordDistance, currentDistance);

  if (previousRecord != recordDistance) {
    console.log(recordDistance);
  }
}
