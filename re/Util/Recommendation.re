type practicalInfo = {
  contact: string,
  hours: string,
  location: string,
};

type place = {
  title: string,
  rating: int,
  tagline: string,
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
    tagline: "Tagline",
    description: "The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit...",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/montserrat.png",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    rating: 4,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: See,
  },
  {
    uuid: "2",
    title: "Santa Ceviche",
    tagline: "Tagline",
    description: "Uno de los mejores restaurantes de comida peruana. Empezar con los choricitos, seguir con un buen ceviche y por ultimo una jalea...",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/santa-ceviche.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    rating: 5,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: Eat,
  },
  {
    uuid: "3",
    title: "Sagrada Familia",
    tagline: "Top choice church",
    description: {js|If you have time for only one sightseeing outing, this should be it. La Sagrada Família inspires awe by its sheer verticality, and in the manner of the medieval cathedrals it emulates, it's still under construction. Work began in 1882 and is hoped (perhaps optimistically) to be completed in 2026, a century after the architect's death. Unfinished it may be, but it attracts around 2.8 million visitors a year and is the most visited monument in Spain.\n\n Some other sentence.\n\n Another test.|js},
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
    rating: 3,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: See,
  },
  {
    uuid: "4",
    title: "Boqueria",
    tagline: "Tagline",
    description: "From December 1470 onwards, a pig market was held at this site; at this time it was known as Mercadi Bornet. Later, until 1794, it was known...",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/boqueria.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    rating: 2,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: See,
  },
  {
    uuid: "5",
    title: "Quimet & Quimet",
    tagline: "Tagline",
    description: "Contemporary tapas menu with unusual and imaginative combinations of ingredients. Take for example the montadito: smoked salmon, Greek yogurt and truffled honey...",
    image:
      BsReactNative.Image.(
        Required(
          BsReactNative.Packager.require(
            "../../../../assets/images/quimet-quimet.jpg",
          ),
        )
      ),
    practicalInfo: {
      contact: "93 208 04 14\nSagradafamilia.es",
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    rating: 3,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
    category: Eat,
  },
  {
    uuid: "6",
    title: "Bar La Plata",
    tagline: "Tagline",
    description: "Very cosy small local restaurant. They don't have enough seats. Ready to eat while standing. They do same 5 tapas since 1945....",
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
      hours: "9am-8pm apr-sep\n9am-6pm oct-mar",
      location: "Carrer de Mallorca 401\nBarcelona, Spain",
    },
    rating: 3,
    recommendation: "Great climbing spot. Bring your rope and shoes!",
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