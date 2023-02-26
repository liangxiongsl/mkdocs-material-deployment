set port=8000
start http://localhost:%port% 
title ji - %port%
mkdocs serve -a localhost:%port%
