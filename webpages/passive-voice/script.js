function scriptChecking() {
  var wrapperDiv = document.getElementById('scriptCheck');
  var existingImage = document.getElementById('noScript');
  var newImage = document.createElement('img');
  newImage.src = 'assets/images/complete.svg';
  var currentText = document.querySelector('.exercise-caution-wrapper-margin-script-text');
  var newParagraph = document.createElement('p');
  newParagraph.textContent = 'Script is currently enabled.';
  wrapperDiv.replaceChild(newImage, existingImage);
  currentText.replaceChild(newParagraph, currentText.firstElementChild);
  var exerciseBottomBreak = document.getElementsByClassName("exercise-caution-wrapper-margin-hr-bottom");
  var exerciseAttemptButton = document.getElementsByClassName("exercise-caution-wrapper-margin-button");
  exerciseBottomBreak[0].style.display = "block";
  exerciseAttemptButton[0].style.display = "flex";
}

document.addEventListener('DOMContentLoaded', function () {
  scriptChecking();
});

function showExercise() {
  var exerciseMainElements = document.getElementsByClassName("exercise-main");
  var exerciseCautionElements = document.getElementsByClassName("exercise-caution");
  exerciseMainElements[0].style.display = "flex";
  exerciseCautionElements[0].style.display = "none";
}

function getHiddenProp() {
  var prefixes = ['webkit', 'moz', 'ms', 'o'];
  if ('hidden' in document) return 'hidden';
  for (var c = 0; c < prefixes.length; c++) {
    if ((prefixes[c] + 'Hidden') in document) {
      return prefixes[c] + 'Hidden';
    }
  }
  return null;
}

function handleVisibilityChange() {
  if (document.visibilityState === 'visible') {
    window.location.reload(true);
  } else if (document.visibilityState !== 'visible') {
    var exerciseMainElements = document.getElementsByClassName("exercise-main");
    var exerciseCautionElements = document.getElementsByClassName("exercise-caution");
    exerciseMainElements[0].style.display = "none";
    exerciseCautionElements[0].style.display = "none";
  }
}

document.addEventListener('visibilitychange', handleVisibilityChange);
