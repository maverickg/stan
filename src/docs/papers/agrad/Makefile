.PHONY: agrad-rev.pdf

agrad-rev.pdf: agrad-rev.tex stan-papers.sty
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode -file-line-error"

clean-all:
	rm -f *.aux *.bbl *.blg *.brf *.log *.fls *.fdb_latexmk *.out agrad-rev.pdf

