library(stringi)
library(plotly)
library(shiny)
#library(googleVis)
path1<-"C:\\LUCIANA\\CE230\\SIGTRAC\\amostracriancas.csv"

setwd("C:\\LUCIANA\\CE230\\SIGTRAC\\")
  
# df <-read.csv(path1,header=TRUE,fill=TRUE,sep=";",strip.white=TRUE)
# 
# status <- c("Non urgent", "Standard","Emergent","Urgent", "Very urgent")
# hosp_status <- c("yes","no")
# 
# for (i in 1:dim(df)[1]){
#   
#   df$MTS.Orig[i] <- grep(df$Original.MTS[i],status)
#   df$MTS.11[i] <- grep(df$MTS.1[i],status)
#   df$MTS.Cur[i] <- df$MTS.11[i]-df$MTS.Orig[i]
#   aux <- as.numeric(stri_replace_all(df$Age[i], ".", fixed=","))  
#   df$Age.1[i] <- as.numeric(gsub('(.*)(.*?)([.].*)',replacement="\\1",x = aux))
#   df$Temperature.1[i] <- as.numeric(stri_replace_all(df$Temperature[i], ".", fixed=","))  
#   df$Respiratory.rate.1[i] <- as.numeric(df$Respiratory.rate[i])
#   df$Oxygen.saturation.1[i] <- as.numeric(df$Oxygen.saturation[i])
#   df$Arrival.date.1[i] <- format(strptime(df$Arrival.date[i],format="%d.%m.%Y"),"%d-%m-%Y")
#   df$Hospitalisation.1[i] <- grep(df$Hospitalisation[i],hosp_status)
#   
#   i <- i+1
#   
# }
shinyServer(function(input, output,session) {
modeltable <- eventReactive( input$do, {
  
#    datainicio <- toString(input$dates[1])
#    datafim <- toString(input$dates[2])
#    
#    datainicio <- format(strptime(datainicio,format="%Y-%m-%d"),"%d-%m-%Y")
#    datafim <- format(strptime(datafim,format="%Y-%m-%d"),"%d-%m-%Y")
  
  df <- df#load("SIGTRAC_Data.RData")
  #df1 <- df[df$'Arrival.date.1'>datainicio & df$'Arrival.date.1'<datafim,]
  #df1 <- df[df$Age=="2",]
  lista <- df
  
 # lista <- list(a=datainicio,b=datafim)
  lista
})

output$dados <- renderDataTable( {
  
  if ( input$do == 0 ) {
    
    return()      
    
  } else {

    model <- modeltable()
  }
  return(model)
  
} )



output$histograma <- renderPlotly( {
  
  df <- modeltable()
  
  a<-df[df$MTS.Orig=='1',14]
  b<-df[df$MTS.Orig=='2',14]
  c<-df[df$MTS.Orig=='3',14]
  d<-df[df$MTS.Orig=='4',14] 
  e<-df[df$MTS.Orig=='5',14]
   
  plot_ly(x=a,opacity=0.6,type="histogram",text = "pessoas",name = status[1]) %>%
    add_trace(x=b,opacity=0.6,type="histogram",text = "pessoas",name = status[2]) %>%
    add_trace(x=c,opacity=0.6,type="histogram",text = "pessoas",name = status[3]) %>%
    add_trace(x=d,opacity=0.6,type="histogram",text = "pessoas",name = status[4]) %>%
    add_trace(x=e,opacity=0.6,type="histogram",text = "pessoas",name = status[5]) %>%
    layout(barmode="overlay")

})
})