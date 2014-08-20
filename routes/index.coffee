express = require("express")
router = express.Router()

Arduino = require "../arduino/index"

# GET home page. 
router.get "/", (req, res) ->
  res.render "layout",
    title: "Express"


# Arduino API
# 
# GET /on          - enable led
# GET /off         - disable led
# 
# 
router.get "/api/on", (req, res) ->
  Arduino.enable (err) ->
    res.json result: unless err then "ok" else "error"

router.get "/api/off", (req, res) ->
  Arduino.disable (err) ->
    res.json result: unless err then "ok" else "error"



module.exports = router
