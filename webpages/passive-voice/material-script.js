const currentDate = new Date();

const year = currentDate.getFullYear();
const month = currentDate.getMonth();
const day = currentDate.getDate();
const hours = currentDate.getHours();
const minutes = currentDate.getMinutes();
const seconds = currentDate.getSeconds();

const minuteVar = 15;
const hourVar = 13;
const dateVar = 27;
const monthVar = 10;
const yearVar = 2023;

const expMin = 59;
const expHour = 14;
const expDate = 27;
const expMonth = 10;
const expYear = 2023;

function timeChecking(currentDate) {
  const setDate = new Date(yearVar, monthVar, dateVar, hourVar, minuteVar);
  const expireDate = new Date(expYear, expMonth, expDate, expHour, expMin);
  var exerciseBefore = document.getElementsByClassName("container-content-exercise-not-begin");
  var exerciseToDo = document.getElementsByClassName("container-content-exercise");
  var exerciseFinished = document.getElementsByClassName("container-content-exercise-has-finished");
  if (currentDate < setDate) {
    exerciseBefore[0].style.display = "block";
    exerciseToDo[0].style.display = "none";
    exerciseFinished[0].style.display = "none";
  } else if (currentDate > setDate && currentDate < expireDate) {
    exerciseBefore[0].style.display = "none";
    exerciseToDo[0].style.display = "block";
    exerciseFinished[0].style.display = "none";
  } else if (currentDate > expireDate) {
    exerciseBefore[0].style.display = "none";
    exerciseToDo[0].style.display = "none";
    exerciseFinished[0].style.display = "block";
  }
  setTimeout(timeChecking, 1000);
}

document.addEventListener('DOMContentLoaded', function () {
  timeChecking(currentDate);
});
