$ ->
  $(window).on "touchmove", (e) ->
    e.preventDefault()

  $(".one").on "touchstart mousedown", (e) ->
    $.get "/api/on"
  $(".two").on "touchstart mousedown", (e) ->
    $.get "/api/off"


