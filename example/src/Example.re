%raw
{|require('isomorphic-fetch')|};

let get = (url, decode) =>
  Js.Promise.(
    Fetch.fetchWithInit(url, Fetch.RequestInit.make(~method_=Get, ()))
    |> then_(Fetch.Response.json)
    |> then_(json => json |> decode |> resolve)
  );

let v: Meetup_t.events =
  get(
    "http://localhost:8000/events",
    Atdgen_codec_runtime.Decode.decode(Meetup_bs.read_events),
  );
