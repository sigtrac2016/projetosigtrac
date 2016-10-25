library(shiny)
require(plotly)

shinyUI(function(input, output, session){
  navbarPage("HOSPITAL",
    tabPanel("Pacientes",
      br(),
      fluidPage(
      sidebarLayout(
        sidebarPanel(
          br(),
       #   dateRangeInput("dates", label = "Periodo",width="60%"),
          actionButton("do", label = "Visualizar")
        ),
        mainPanel( 
          tabsetPanel(
            tabPanel("Dados",dataTableOutput (outputId="dados")),
            tabPanel("Histograma",plotlyOutput("histograma"))
          )#tabsetPanel
        )#mainPanel
      )#sidebarLayout
    )#fluidPage
  )#tabPanel
)#navbar
})#shiny
