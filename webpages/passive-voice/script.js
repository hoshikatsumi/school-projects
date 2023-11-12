function showExercise() {
  var exerciseMainElements = document.getElementsByClassName("exercise-main");
  var exerciseCautionElements = document.getElementsByClassName("exercise-caution");
  exerciseMainElements[0].style.display = "flex";
  exerciseCautionElements[0].style.display = "none";
}

function getHiddenProp() {
  var prefixes = ['webkit', 'moz', 'ms', 'o'];
  // If 'hidden' is natively supported, just return it
  if ('hidden' in document) return 'hidden';
  // Otherwise loop over all known prefixes until it finds one
  for (var c = 0; c < prefixes.length; c++) {
    if ((prefixes[i] + 'Hidden') in document) {
      return prefixes[i] + 'Hidden';
    }
  }
  // Otherwise it is not supported
  return null;
}

function handleVisibilityChange() {
  if (document.visibilityState === 'visible') {
    // Page is visible, reload the page
    window.location.reload(true);
  }
}

// Listen for visibility change events
document.addEventListener('visibilitychange', handleVisibilityChange);
