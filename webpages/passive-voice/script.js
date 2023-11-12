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

// Function to apply blur when the page is not currently viewed
function applyBlurOnVisibilityChange() {
  // Check for browser support
  if (document.hidden !== undefined) {
    // Listen for visibility change events
    document.addEventListener('visibilitychange', handleVisibilityChange);
  } else if (document.mozHidden !== undefined) {
    document.addEventListener('mozvisibilitychange', handleVisibilityChange);
  } else if (document.msHidden !== undefined) {
    document.addEventListener('msvisibilitychange', handleVisibilityChange);
  } else if (document.webkitHidden !== undefined) {
    document.addEventListener('webkitvisibilitychange', handleVisibilityChange);
  }
}

// Function to handle visibility change
function handleVisibilityChange() {
  if (document.hidden || document.mozHidden || document.msHidden || document.webkitHidden) {
    // Blur page if the page is not visible
    blurContent();
  } else {
    // Page is visible, reload the page
    window.location.reload(true);
  }
}

// Function to apply blur effect
function blurContent() {
  document.body.style.filter = 'blur(10px)';
}

// Call the function to start monitoring visibility changes
applyBlurOnVisibilityChange();
