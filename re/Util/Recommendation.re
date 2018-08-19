type practicalInfo = {
  contact: string,
  hours: string,
  location: string,
};

type place = {
  title: string,
  tagline: string,
  teaser: string,
  description: string,
  image: BsReactNative.Image.imageSource,
  category: Category.category,
  practicalInfo,
  recommendation: string,
  uuid: string,
};

let recommendations = [|
  {
    uuid: "1",
    title: "Montserrat",
    tagline: "Monastery perched on vertical rock",
    teaser: {js|The holy church on top of a mountain is a wonderful place to visit, worship, and climb.|js},
    description: {js|Montserrat literally means a "saw mountain", because seen from a far it resembles the sharp teeth of a saw. Somewhere above the countless rock pillars and needles sits a monastery with a beautiful church.\n\nYou can get there by car (if you're early enough to still find a spot on the parking lot), or a cable car. from the town down below. Alternatively, you can take a wonderful, long via ferrata (an equiped climbing route) that goes straight up the rock walls and ends climbing over the fence ont a panoramic view platform on one of the highest points on the mountain. Only recommended if you've done via ferratas before and you know what you're getting yourself into!|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/montserrat.png",
          ),
        )
      ),
    practicalInfo: {
      contact: "montserratvisita.com",
      hours: "From 7.30 am to 8 pm.",
      location: {js|Montserrat 🤷‍♂️|js},
    },
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: See,
  },
  {
    uuid: "2",
    title: {js|Take a bicycle tour|js},
    tagline: {js|Explore the city at your own pace|js},
    teaser: {js|Explore the city at your own pace.|js},
    description: {js|Barcelona has more than 200 km of bicycle lanes, you should take advantage of them! The city is quite walkable, but getting a bicycle is taking the whole experience to a different level. \n\n You don't need to follow any organised tours, just pick a direction and go. From the top of Park Güell down to Barceloneta there's plenty of places to see. One of many nice rides is going from Gràcia district down Passeig de Sant Joan, passing the Arc de Triomf and following still the same straight line to Parc de la Ciutadella. There you can lie down on the grass and take a break, or pedal a bit more to the beach.\n\nEnjoy!|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/bicycle.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: {js|🙅‍♂️|js},
      hours: "Open all hours",
      location: {js|The whole city is yours|js},
    },
    recommendation: {js|Be careful, respect the traffic lights, and don't run anybody over!|js},
    category: Do,
  },
  {
    uuid: "3",
    title: {js|Festa Major de Gràcia|js},
    tagline: {js|7 days of celebrations|js},
    teaser: {js|Experience 7 days of celebrations.|js},
    description: {js|Each year in August there's a big, 7-day party that takes over the Gràcia district. In 2018 it starts on the 15th and ends on 21st, so hurry up! \n\n There are street concerts, plenty of people, in promptu bars, but the most surprising attraction are the decorated streets. Local community each year runs a competition for the best decorated street. The theme can be anything, I've seen zombies, classical music, underwater world, pirates, and basically anything in-between.\n\nIf you're in Barcelona in August, make sure to check the dates and enjoy the longest party in town!|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/gracia.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "festamajordegracia.cat",
      hours: "All day and most of the night",
      location: {js|District of Gràcia|js},
    },
    recommendation: {js|It's good to get there on the first days, before the street decorations get damaged.|js},
    category: Do,
  },
  {
    uuid: "4",
    title: {js|Fountain of Montjuïc|js},
    teaser: {js|Experience a music and light show almost every evening.|js},
    tagline: {js|Evening music + light show|js},
    description: {js|The so-called Magic Fountain of Montjuïc is situated between Plaça d'Espanya and Museu Nacional d’Art de Catalunya. During the day it's just a normal fountain, but in the evening it offers a unique performance. The flow of water is synchronised with music and highlightes with special lights. \n\n The whole experience is best viewed from the top of the stairs leading to MNAC. If you're in doubt whether it's your thing, just bring a bottle of wine to enjoy. \n\n Performance times depend on the time of year. From October to December and February to April, shows are on Fridays and Saturdays from 7 p.m. to 9 p.m. From May to September, shows are held Thursday to Sunday from 9 p.m. to 11:30 p.m.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/fountain.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "barcelona.cat/fontmagica",
      hours: "Varies, see description above",
      location: {js|Plaça de Carles Buïgas 1, Barcelona|js},
    },
    recommendation: {js|Remember to pack a bottle of wine with you!|js},
    category: Do,
  },
  {
    uuid: "5",
    title: "Santa Ceviche",
    teaser: {js|Small restaurant that lies off the beaten path and serves great Peruvian food. Think: ceviche.|js},
    tagline: "Great ceviche, off the beaten path",
    description: {js|It's a great Peruvian restaurant nearby Plaça d'Espanya. Small, off the beaten path, family-run, all of it gives it a nice atmosphere. You should start with some choricitos, then ceviche with the spicy sauce, finishing with a jalea. Sharing the food with others, of course, because that's how it tastes better.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/santa-ceviche.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "+34 932 696 148\nsantaceviche.com",
      hours: "Tue-Sat: 13-16h and 20-23h\nSunday: 13-16h",
      location: "Carrer d'Hostafrancs de Sió 11",
    },
    recommendation: "Can't recommend it enough! It's my favourite restaurant in Barcelona.",
    category: Eat,
  },
  {
    uuid: "6",
    title: {js|Ciudad Condal|js},
    tagline: {js|Good tapas in the city centre|js},
    teaser: {js|It's difficult to find good tapas in the city center. So we found one for you.|js},
    description: {js|I always have a problem to recommend a good tapas place in the city centre. It's difficult to find some middle ground between the sterile tourist traps and local hole-in-the-wall places where you feel you might permanently stick to the chair if you sit down.\n\nFortunately, there's always Ciudad Condal. They offer good tapas, nice beer selection, reasonably priced, in a great location, just off Passeig de Gracia. They have all the classics in the menu: patatas bravas, pimientos del padron, boquerones, etc. If you don't know what to eat, just take a spot at the bar and point with your finger.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/ciudad-condal.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "+34 933 181 997",
      hours: "It's complicated, but it's usually open",
      location: {js|Rambla de Catalunya 18|js},
    },
    recommendation: {js|Great place for introduction to tapas. Tasty, good location, stuff speaks English.|js},
    category: Eat,
  },
  {
    uuid: "7",
    title: {js|Laberint d'Horta|js},
    tagline: {js|Get lost in a real Victorian labirynth|js},
    teaser: {js|Get lost in a Victorian labirynth and find great views of the city.|js},
    description: {js|Although on the map it looks really far away from the center, this wonderful city park is easily accessible with the green metro line.\n\nApart from the main attraction - a real hedge maze - you will also find green terraces, great views over the city and at the top a romantic garde with a tiny hidden waterfall.\n\nDefinitely worth the metro ride.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/horta.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "bcn.cat",
      hours: "10am - 8pm",
      location: {js|Passeig Castanyers 1|js},
    },
    recommendation: {js|If you get lost, there's a map of the maze on Wikipedia!|js},
    category: See,
  },
  {
    uuid: "9",
    title: "Sagrada Familia",
    tagline: "Top choice church",
    teaser: {js|If this church won't amaze you, the project's timeline will.|js},
    description: {js|If you have time for only one sightseeing outing, this should be it. The Sagrada Família church inspires awe by its sheer verticality and beautiful light. Also, in the manner of the medieval cathedrals it emulates, it's still under construction.\n\nWork began in 1882 and it's hoped (perhaps optimistically) to be completed in 2026, a century after the architect's death. Unfinished it may be, but it attracts around 2.8 million visitors a year and is the most visited monument in Spain.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/sagrada-familia.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    recommendation: "Get your ticket online to jump the huge queue!",
    category: See,
  },
  {
    uuid: "10",
    title: "La Boqueria",
    tagline: "Most photographic food market in Barcelona",
    teaser: {js|Come here to get your instagram shots of a "typical Spanish market".|js},
    description: "From December 1470 onwards, a pig market was held at this site; at this time it was known as Mercadi Bornet. Later, until 1794, it was known as Mercat de la Palla. Now, its full name is Mercat de Sant Josep de la Boqueria, but you don't need to know that.\n\nWhat you need to know is this is the place to go to look (and take great shots) of all the colourful varieties of typical Spanish food. My personal favourite is the fish part. You can get a small snack there, but if you plan a real meal, it'll get rather expensive.",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/boqueria.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "boqueria.barcelona",
      hours: "mon-sat: 8am - 8.30pm",
      location: "Rambla 91, 08001 Barcelona",
    },
    recommendation: {js|Remember there's a reason it's in a "to see", not "too eat", category.|js},
    category: See,
  },
  {
    uuid: "11",
    title: "Quimet & Quimet",
    tagline: "Crowded, busy, noisy - a real tapas place",
    teaser: {js|A definite step up from our introductory Tapas 101 recommendation.|js},
    description: "This tiny restaurant serves contemporary tapas menu with unusual and imaginative combinations of ingredients. Take for example one of their montaditos (tiny sandwiches): smoked salmon, Greek yogurt and truffled honey. Surprising flavour combinations, but one thing is constant: they're all great.\n\nHowever, this is not as easy to navigate as our introductory tapas recommendation. Be prepared for stuff that might not speak English, no sitting places, and crowds passing by.\n\nIt's a rushed place, so get in, get some food in you and keep going.",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/quimet.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "+34 934 423 142",
      hours: "Mon-fr:\n12:00 - 16:00, 19:00 - 22:30",
      location: "Carrer del\nPoeta Cabanyes 25",
    },
    recommendation: "If you don't manage to find a spot, take a walk down Carrer de Blai to hunt down something there",
    category: Eat,
  },
  {
    uuid: "12",
    title: "Bar La Plata",
    tagline: "Quality trumps quantity",
    teaser: {js|A tiny bar that serves the same four tapas since 1945.|js},
    description: "Very cosy small local bar. They serve the same 4 tapas since 1945 along with great wine. Makes it easy to order.\n\nIt's a great place, but I wouldn't recommend it as the first encounter with Spanish tapas traditions. It's not flashy, but rather down-to-earth place that focuses on making simple things perfect.\n\nA bit like Pepe Dreams of Fried Fish.",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/bar-la-plata.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "Mon-sat:\n9.00-15.15 and 18.15-23.00",
      location: {js|C/ Mercè 28,\n08002 Barcelona|js},
    },
    recommendation: "Fried fish and vermut.",
    category: Eat,
  },
  {
    uuid: "13",
    title: {js|Taverna Can Margarit|js},
    tagline: {js|Great traditional food|js},
    teaser: {js|A place for an evening out with friends, wine, and good food.|js},
    description: {js|Started in 1974, this tavern keeps the traditional informal dining style. The menu is based on a small collection of simple, traditional dishes.\n\nEverything tastes like your Grandma would cook it, if she were Catalan.|js},
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/margarit.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "+34 934 416 723",
      hours: "Mon-sat: 20:30-24h",
      location: {js|Carrer de la Concòrdia 21|js},
    },
    recommendation: {js|Make sure to get a reservation!|js},
    category: Eat,
  },
|];

let filteredRecommendations = filter =>
  Array.of_list(
    List.filter(
      place => filter == Category.All || filter == Category(place.category),
      Array.to_list(recommendations),
    ),
  );

let find = uuid =>
  List.find(place => place.uuid == uuid, Array.to_list(recommendations));